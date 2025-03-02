# ***********************************************************************************
# ***                        PDF to TXT Converter                                 ***
# ***                        27 Feb 2025 01:37 AM                                 ***
# ***                                                                             ***
# ***          before using it please read Documentation.html file                ***
# ***               this script is developed by Irshad Hossain                    ***
# ***                     Software Engineer , BDU                                 ***
# ***********************************************************************************




import os
import fitz  # PyMuPDF
import pytesseract
from pdf2image import convert_from_path
from PIL import Image
from tqdm import tqdm  # Progress bar
import time  # For animations
import shutil  # Terminal size
import sys  # For inline printing

GREEN = "\033[92m"
RESET = "\033[0m"

conversion_records = []  # Store converted files


convert_count = 1

# ✅ Function to clear the screen when needed
def clear_screen():
    os.system("cls" if os.name == "nt" else "clear")

def StartConvert(): 
    global convert_count
    os.system("cls" if os.name == "nt" else "clear")
    print(f"\n\t Conversion No {convert_count} th")
    convert_count += 1


# ✅ Check Dependencies Before Execution
def check_dependencies():
    dependencies = ["fitz", "pytesseract", "pdf2image", "PIL", "tqdm"]
    missing = []
    for dep in dependencies:
        try:
            __import__(dep)
        except ImportError:
            missing.append(dep)

    if missing:
        print("\n❌ Missing dependencies detected!")
        print("Run the following command to install them:")
        print(f"pip install {' '.join(missing)}\n")
        exit()

# ✅ Set Tesseract Path for Windows
pytesseract.pytesseract.tesseract_cmd = r"C:\Program Files\Tesseract-OCR\tesseract.exe"

# ✅ Set Poppler Path (if not added to PATH)
POPPLER_PATH = r"C:\Program Files\Poppler\poppler-24.08.0\Library\bin"

def pdf_to_text_ocr(pdf_path, txt_path):
    try:
        print("\n📄  PDF to Text OCR Converter")
        print("=" * 40)
        StartConvert()
        print("\n🔄 Converting PDF to images...\n")
        time.sleep(1)
        images = convert_from_path(pdf_path, poppler_path=POPPLER_PATH)
        text = ""

        print("✅ PDF Loaded! Processing OCR...\n")

        # Get terminal width
        term_width, _ = shutil.get_terminal_size()
        bar_width = max(30, term_width - 30)  # Ensuring the progress bar doesn't overflow

        # Progress Bar with ETA aligned
        progress_bar = tqdm(
            images,
            desc="Processing Pages",
            ncols=term_width - 5,
            ascii=" █",
            bar_format="{desc}: {percentage:3.0f}%|{bar:40}|     Page: {n_fmt}/{total_fmt} {postfix}    [{elapsed}\033[91m<{remaining}\033[0m, {rate_fmt}]"
        )

        for i, img in enumerate(progress_bar):
            page_text = pytesseract.image_to_string(img)
            text += f"\n--- Page {i+1} ---\n" + page_text

        with open(txt_path, "w", encoding="utf-8") as txt_file:
            txt_file.write(text)

        print(f"\n\t🎉 OCR Completed! Text saved to: \033[92m{txt_path}\033[0m\n")
        # ✅ Store the conversion record
        conversion_records.append((pdf_path, txt_path))


    except Exception as e:
        print(f"\n❌ Error: {e}")

if __name__ == "__main__":
    clear_screen()
    check_dependencies()

    while True:  # 🔄 Loop for multiple conversions
        clear_screen()
        print("\n\t📄  PDF to Text OCR Converter")
        print("=" * 40)

        pdf_path = input("\n  Path of PDF file ➤   ").strip()
        while not os.path.exists(pdf_path):
            print("❌ File not found! Please enter a valid path.")
            pdf_path = input("\n  Path of PDF file ➤  ").strip()

        txt_path = input("\n  Path of TXT file ➤  ").strip()

        
        pdf_to_text_ocr(pdf_path, txt_path)

        # 🔄 Ask if the user wants to convert another file
        print("\n  🔁 Convert another PDF? (yes/no)")
        choice = input("➤   ").strip().lower()
        if choice not in ["yes", "y"]:
            
            # ✅ Show all conversions before exiting
            if conversion_records:
                print("\n📊 Conversion Summary:")
                print("*" * 50)
                print(f"{'ID':<4} | {'PDF FILE':<30} -> {'TXT FILE':<30}")
                print("-" * 50)
                for idx, (pdf, txt) in enumerate(conversion_records, 1):
                    print(f"{idx:<4} | {pdf:<30} \t->\t {txt:<30}")
                print("_" * 50)
                print(f"\n✅ Total Conversions: {len(conversion_records)}\n")
                
                     

            # ✅ Ask for final confirmation before exiting
            final_choice = input("\n⚠️  Do you want to exit? (yes/no) ➤  ").strip().lower()
            if final_choice not in ["yes", "y"]:
                continue  # Restart the process instead of exiting
            else:
                print("\n👋 Exiting... Have a great day!\n")
                break  # 🔚 Exit loop if user doesn't want another conversion
