/*
 * -----------------------------------------------------------
 * |                                                         |
 * |          Library Management System (LMS) V 1.0.1        |
 * |                                                         |
 * |           Last Modified: 28 Feb, 2025 10:36 AM          |
 * |              Developed by: Irshad Hossain               |
 * |                                                         |
 * -----------------------------------------------------------
 
    Task will be added soon .
 
 - LOGIN Unicode Art - [x]
 - Login verification problem - [x]


 
 
 
 */



 #include <stdio.h>
 #include <stdlib.h>
 #include <conio.h>
 #include <unistd.h>
 #include <windows.h>
 
 
 
 typedef struct {
     int id;
     char username[50];
     char email[100];
     char password[50];
     int borrowed_books[10];  // Added
     int borrowed_count;      // Added
 } User;
 
 typedef struct {
     int bookID;
     char title[100];
     char author[100];
     int is_borrowed;         // Added
 } Book;
 
 
 
 
 
 
 
 
 // Function prototypes
 
 void initialize_file();
 void loading(int duration);
 void clear_screen();
 int button_two(const char t1[20], const char t2[20]);
 int button_three(const char t1[20], const char t2[20], const char t3[20]);
 void press_any_key();
 void welcome(int a);
 void Admin(int a);
 void UserScreen(int a);
 void StartMenue();
 void AdminMenue();
 void ManageBooksMenue();
 void UserMenue(int userID);
 void login();
 int VerifyLogin(char username[], char password[]);
 void AdminPortal();
 void ViewBooks();
 void ManageBooks();
 void AddBooks();
 int GenerateBookID();
 void AddBookData(Book book);
 void AddBooksSuccess(Book book);
 void DeleteBooks();
 void DeleteBook(int bookID);
 void ViewUsers();
 void ViewUser(int userID);
 void DeleteUser(int userID);
 void Library();
 int CheckUserExists(char username[]);
 void register_user();
 int GenerateUserID();
 void register_user_success(User user);
 void ViewBooksUsr(int userID);
 void SearchBooksUsr(int userID);
 Book *SearchBookByID(int bookID);
 void BorrowBooksUsr(int userID);
 void BorrowBook(int userID, int bookID);
 void ReturnBooks(int userID);
 void ReturnBook(int userID, int bookID);
 void BooksHistoryUsr(int userID);
 void LogoutUsr();
 void UserPortal(int userID);
 void ResetBooks();
 void ResetUsers();
 void ResetLibrary();
 void BackupBooks();
 void RemoveBookFromUsers(int bookID);
 void ManageUser();
 void BorrowSuccess();
 void ReturnSuccess(int userID); 
 User* GetUser(int userID);
 void Library_guest();
 
 
 char VERSION[10] = "1.0.1";
 
 
 
 #define MAX_BOOKS 100
 #define MAX_USERS 100
 
 
 
 void initialize_file()
 {
     FILE *file = fopen("users.dat", "ab"); // Open in append mode
     if (file == NULL)
     {
         printf("\nError creating file!\n");
         exit(1); // Exit program if file creation fails
     }
     fclose(file); // Close the file after ensuring it exists
 }
 
 int main()
 {
     system("cls");
     welcome(200);
     printf("\t---+-----+------   Library Management System   ---+-----+------\n\nWelcome to Library Management System (LMS) V 1.0.1\n\n");
     StartMenue();
     return 0;
 }
 
 // Functions for the Library Management System
 // Accessories
 
 
 
 void loading(int duration)
 {
     char symbols[] = {'\\', '|', '/', '-'};
     int symbolCount = 4;
     int delay = 200000;
 
     printf("\nWorking  ");
     fflush(stdout);
 
     for (int i = 0; i < (duration * 1000000) / delay; i++)
     {
         printf("\b%c", symbols[i % symbolCount]); // Overwrite the last character with animation
         fflush(stdout);
         usleep(delay);
     }
 
     // Erase "Working  " completely before printing "Logging out..."
     printf("\r          \r"); 
     fflush(stdout);
 }
 
 
 
 void clear_screen()
 {
     system("cls");
 }
 
 int button_two(const char t1[20], const char t2[20])
 {
     printf("\033[35m");
     printf("\n\n\t[%s]\t[%s]\n\n", t1, t2);
     fflush(stdout);
 
     int a;
     scanf("%d", &a);
     printf("\033[0m");
 
     if (a == 1)
     {
         return 1;
     }
     else if (a == 2)
     {
         return 2;
     }
 }
 
 int button_three(const char t1[20], const char t2[20], const char t3[20])
 {
     printf("\033[35m");
     printf("\n\n\t[%s]\t[%s]\t[%s]\n\n", t1, t2, t3);
     fflush(stdout);
 
     int a;
     scanf("%d", &a);
     printf("\033[0m");
 
     if (a == 1)
     {
         return 1;
     }
     else if (a == 2)
     {
         return 2;
     }
     else if (a == 3)
     {
         return 3;
     }
 }
 
 void press_any_key()
 {
     printf("Press any key to continue...\n");
     getch();
     loading(1);
     // system("cls");
 }
 
 // Menue functions
 
 void welcome(int a)
 {
     int space = 18;
     const char *art[] = {
         "  _        __  __    _____ ",
         " | |      |  \\/  |  / ____|",
         " | |      | \\  / | | (___  ",
         " | |      | |\\/| |  \\___ \\ ",
         " | |____  | |  | |  ____) |",
         " |______| |_|  |_| |_____/ ",
         "                           "};
 
     int num_lines = sizeof(art) / sizeof(art[0]);
 
     do
     {
 
         for (int i = 0; i < num_lines; i++)
         {
             printf("%*s", space, "");
             SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
             printf("%s\n", art[i]);
             SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
             Sleep(a);
         }
     } while (0);
 }
 
 
 void loginAnimation(int a)
 {
     int space = 6; // Adjust spacing for alignment
     const char *art[] = {
         "                                                  ",
         "  _         ____     _____   _____   _   _        ",
         " | |       / __ \\   / ____| |_   _| | \\ | |      ",
         " | |      | |  | | | |  __    | |   |  \\| |      ",
         " | |      | |  | | | | |_ |   | |   | . ` |      ",
         " | |____  | |__| | | |__| |  _| |_  | |\\  |      ",
         " |______|  \\____/   \\_____| |_____| |_| \\_|      ",
         "                                                  "};
 
     int num_lines = sizeof(art) / sizeof(art[0]);
 
     do
     {
         for (int i = 0; i < num_lines; i++)
         {
             printf("%*s", space, ""); // Add leading spaces for centering
             SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
             printf("%s\n", art[i]);
         }
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Reset color
         Sleep(a);
 
     } while (0);
 }
 
 void regiAnimation(int a)
 {
     int space = 6; // Adjust spacing for alignment
     const char *art[] = {
         "                                                  ",
         "  _____    ______    _____   _____    _____      ",
         " |  __ \\  |  ____|  / ____| |_   _|  / ____|     ",
         " | |__) | | |__    | |  __    | |   | (___       ",
         " |  _  /  |  __|   | | |_ |   | |    \\___ \\      ",
         " | | \\ \\  | |____  | |__| |  _| |_   ____) |  _  ",
         " |_|  \\_\\ |______|  \\_____| |_____| |_____/  (_) ",
         "                                                  "};
 
     int num_lines = sizeof(art) / sizeof(art[0]);
 
     do
     {
         for (int i = 0; i < num_lines; i++)
         {
             printf("%*s", space, ""); // Add leading spaces for centering
             SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
             printf("%s\n", art[i]);
         }
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Reset color
         Sleep(a);
 
     } while (0);
 }
 
 
 void Admin(int a)
 {
     int space = 5;
     const char *art[] = {
         "             _____    __  __   _____   _   _ ",
         "     /\\     |  __ \\  |  \\/  | |_   _| | \\ | |",
         "    /  \\    | |  | | | \\  / |   | |   |  \\| |",
         "   / /\\ \\   | |  | | | |\\/| |   | |   | . ` |",
         "  / ____ \\  | |__| | | |  | |  _| |_  | |\\  |",
         " /_/    \\_\\ |_____/  |_|  |_| |_____| |_| \\_|",
         "                                             ",
         "                                             "};
 
     int num_lines = sizeof(art) / sizeof(art[0]);
 
     for (int i = 0; i < num_lines; i++)
     {
         printf("%*s", space, "");
 
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
 
         printf("%s\n", art[i]);
 
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
 
         Sleep(a);
     }
 
     printf("\n\n");
 }
 
 void UserScreen(int a)
 {
     int space = 2;
     const char *art[] = {
         "  _    _   ______   _        _         ____  ",
         " | |  | | |  ____| | |      | |       / __ \\ ",
         " | |__| | | |__    | |      | |      | |  | |",
         " |  __  | |  __|   | |      | |      | |  | |",
         " | |  | | | |____  | |____  | |____  | |__| |",
         " |_|  |_| |______| |______| |______|  \\____/ ",
         "                                             ",
         "                                             "};
 
     int num_lines = sizeof(art) / sizeof(art[0]);
 
     for (int i = 0; i < num_lines; i++)
     {
         printf("%*s", space, "");
 
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
 
         printf("%s\n", art[i]);
 
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
 
         Sleep(a);
     }
 }
 
 void StartMenue()
 {
     printf("\033[33m");
 
     printf("\n\nPlease select an option:\n 1. Login\n 2. Register\n 3. Library\n 4. Exit\n\n");
 
     int choice;
     printf(">  ");
     fflush(stdout);
 
     printf("\r  ");
     fflush(stdout);
     scanf("%d", &choice);
     printf("\033[0m");
 
     loading(1);
 
     switch (choice)
     {
     case 1:
         loading(1);
         login();
         break;
     case 2:
         loading(1);
         register_user();
         break;
     case 3:
         loading(1);
         Library_guest();
 
         break;
     case 4:
         loading(1);
         printf("Logging out...\n");
         Sleep(1000);
         printf("\nExiting the system. Goodbye!\n");
         exit(0);
     default:
         printf("\nInvalid choice! Please try again.\n");
         break;
     }
 }
 
 void AdminMenue()
 {
     printf("\033[33m");
 
     printf("\n\n1. View Books");
     printf("\n2. Manage Books");
     printf("\n3. View Users");
     printf("\n4. Library");
     printf("\n5. Reset Books");
     printf("\n6. Reset Users");
     printf("\n7. Reset Library");
     printf("\n8. Logout\n\n");
 
 
     int choice;
     printf(">  ");
     fflush(stdout);
 
     printf("\r  ");
     fflush(stdout);
     scanf("%d", &choice);
     printf("\033[0m");
 
     loading(1);
 
     switch (choice)
 {
     case 1:
         ViewBooks();
         break;
     case 2:
         ManageBooks();
         break;
     case 3:
         ViewUsers();
         break;
     case 4:
         Library();
         break;
     case 5: // Reset books
         printf("Resetting books...\n");
         Sleep(1000);
         loading(1);
         ResetBooks();
         break;
     case 6: // Reset users
         printf("Resetting users...\n");
         Sleep(1000);
         loading(1);
         ResetUsers();
         break;
     case 7: // Reset library
         printf("Resetting library...\n");
         Sleep(1000);
         ResetLibrary();
         break;
     case 8: // Logout
         printf("Logging out...\n");
         Sleep(1000);
         StartMenue();
         break;
     default:
         printf("Invalid choice! Please try again.\n");
         AdminMenue();
         break;
     }
 
 }
 
 void ManageBooksMenue()
 {
     printf("\033[33m");
 
     printf("\n\n1. Add Books");
     printf("\n2. Delete Books");
     printf("\n3. Books Status");
     printf("\n4. Back\n\n");
 
     int choice;
     printf(">");
     fflush(stdout);
 
     printf("\r");
     fflush(stdout);
     scanf("%d", &choice);
     printf("\033[0m");
 
     loading(1);
 
     switch (choice)
     {
     case 1:
         loading(0.5);
         AddBooks();
         break;
     case 2:
         loading(0.5);
         DeleteBooks();
         break;
     case 3:
         loading(0.5);
         // BookStatus();
         AdminPortal();
         break;
     case 4:
         loading(0.5);
         AdminPortal();
         break;
     default:
         printf("Invalid choice! Please try again.\n");
         break;
     }
 }
 
 void UserMenue(int userID)
 {
     printf("\033[33m");
 
     printf("\n\n1. View Books");
     printf("\n2. Search Books");
     printf("\n3. Borrow Books");
     printf("\n4. Return Books");
     printf("\n5. Book's History");
     printf("\n6. Logout\n\n");
 
     int choice;
     printf(">  ");
     fflush(stdout);
 
     printf("\r");
     fflush(stdout);
     scanf("%d", &choice);
     printf("\033[0m");
 
     loading(1);
 
     switch (choice)
     {
     case 1:
         loading(0.5);
         ViewBooksUsr(userID);
         break;
     case 2:
         loading(0.5);
         SearchBooksUsr(userID);
         break;
     case 3:
         loading(0.5);
         BorrowBooksUsr(userID); // for trial purpose
         break;
     case 4:
         loading(0.5);
         ReturnBooks(userID); // for trial purpose
         break;
     case 5:
         loading(0.5);
         BooksHistoryUsr(1); // for trial purpose
         break;
     case 6:
         loading(0.5);
         LogoutUsr();
         break;
     default:
         printf("Invalid choice! Please try again.\n");
         loading(1);
         UserPortal(userID);
         break;
     }
 }
 
 // Core functions
 
 void login()
 {
     clear_screen();
     loginAnimation(10);
     char username[50], password[50];
     printf("---+-----+------   Login   ---+-----+------\n\n");
     printf("Username: ");
     scanf(" %[^\n]", username);
     printf("\nPassword: ");
     scanf(" %[^\n]", password);
 
     switch (button_two("Submit", "Back"))
     {
     case 1:
         printf("Logging in...\n");
         Sleep(1000);
         int userID = VerifyLogin(username, password);
         if (userID == -1)
         {
             loading(1);
             AdminPortal();
         }
         else if (userID > 0)
         {
             loading(1);
             UserPortal(userID); // modified - for trial purpose
         }
         else
         {
             printf("\nInvalid username or password.\n");
         }
         break;
     case 2:
         StartMenue();
         break;
     default:
         printf("\n\tInvalid choice! Please try again.\n");
         loading(1);
         login();
         break;
     }
 }
 
 int VerifyLogin(char username[], char password[])
 {
     if (strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0)
     {
         return -1;
     }
 
     FILE *file = fopen("users.dat", "rb");
     if (file == NULL)
     {
         printf("Error opening user database.\n");
         return 0;
     }
 
     User user;
     while (fread(&user, sizeof(User), 1, file))
     {
         if (strcmp(user.username, username) == 0 && strcmp(user.password, password) == 0)
         {
             fclose(file);
             return user.id;
         }
     }
 
     fclose(file);
     return 0;
 }
 
 void AdminPortal()
 {
     clear_screen();
     Admin(10);
     printf("_____________________________\n\n");
 
     AdminMenue();
 }
 
 void ViewBooks()
 {
     clear_screen();
     Admin(10);
     printf("\033[33m");
     printf("\t\t=========================\n");
     printf("\t\t----- View All Books ----\n");
     printf("\t\t=========================\n");
     printf("\033[0m");
 
     FILE *file = fopen("books.dat", "rb");
     if (file == NULL)
     {
         printf("Error opening book database.\n");
         return;
     }
 
     Book book;
     printf("\nList of Books:\n");
     printf("----------------------------\n");
 
     printf("\n\033[33m");
     printf("====================================================================\n");
     printf("| %-5s | %-40s | %-40s | %-10s |\n", "ID", "Title", "Author", "Status");
     printf("====================================================================\n");
     printf("\033[0m");
 
     while (fread(&book, sizeof(Book), 1, file))
     {
         printf("| %5d | %-40s | %-40s | %-10s |\n",
                book.bookID, book.title, book.author,
                book.is_borrowed ? "Borrowed" : "Available");
     }
 
     printf("====================================================================\n");
 
     fclose(file);
 
     switch (button_three("Add Books", "Admin Panel", "Logout & Exit"))
     {
     case 1:
         loading(0.5);
         printf("\n\tAdding books...\n");
         Sleep(1000);
         AddBooks();
         break;
     case 2:
         printf("\n\tRedirecting to Admin...\n");
         Sleep(1000);
         AdminPortal();
         break;
     case 3:
         printf("\n\tLogging out...\n");
         Sleep(1000);
         StartMenue();
         break;
     default:
         printf("\n\tInvalid choice! Please try again.\n");
         break;
     }
 }
 
 void ManageBooks()
 {
     clear_screen();
     Admin(10);
     printf("\033[33m");
     printf("\t\t=========================\n");
     printf("\t\t----- Manage Books ----\n");
     printf("\t\t=========================\n");
     printf("\033[0m");
 
     ManageBooksMenue();
 }
 
 void AddBooks()
 {
     clear_screen();
     Admin(10);
     printf("\033[33m");
     printf("\t\t=========================\n");
     printf("\t\t----- Add Books ----\n");
     printf("\t\t=========================\n");
     printf("\033[0m");
 
     Book book;
 
     printf("\n\nBook name: ");
     scanf(" %[^\n]", book.title);
     printf("\nAuthor name: ");
     scanf(" %[^\n]", book.author);
 
     switch (button_two("Submit", "Back"))
     {
     case 1:
         printf("\n\tAdding books...\n");
         Sleep(1000);
         AddBooksSuccess(book);
         break;
     case 2:
         ManageBooks();
         break;
     default:
         printf("\n\tInvalid choice! Please try again.\n");
         break;
     }
 }
 
 int GenerateBookID()
 {
     FILE *file = fopen("books.dat", "rb");
     if (file == NULL)
     {
         return 1; // Start from ID 1 if no file exists
     }
 
     Book book;
     int lastID = 0;
     while (fread(&book, sizeof(Book), 1, file))
     {
         lastID = book.bookID;
     }
 
     fclose(file);
     return lastID + 1; // Next book ID
 }
 
 void AddBookData(Book book)
 {
     FILE *file = fopen("books.dat", "ab"); // Open file in append mode
     if (file == NULL)
     {
         printf("Error opening book database.\n");
         return;
     }
 
     fwrite(&book, sizeof(Book), 1, file); // Write book data to file
     fclose(file);
 
     printf("\n✅ Book added successfully: %s by %s (ID: %d)\n", book.title, book.author, book.bookID);
 }
 
 void AddBooksSuccess(Book book)
 {
     clear_screen();
     Admin(10);
     printf("\033[33m");
     printf("\t\t=========================\n");
     printf("\t\t----- Add Books ----\n");
     printf("\t\t=========================\n");
     printf("\033[0m");
 
     book.bookID = GenerateBookID();
     AddBookData(book);
 
     printf("\nBook added successfully! ID: %d\n", book.bookID);
 
     switch (button_two("Add another book", "Done"))
     {
     case 1:
         AddBooks();
         break;
     case 2:
         loading(1);
         ManageBooks();
         break;
     default:
         printf("\n\tInvalid choice! Please try again.\n");
         break;
     }
 }
 
 void DeleteBooks()
 {
     clear_screen();
     printf("\033[33m");
     printf("\t\t=========================\n");
     printf("\t\t----- Delete Books ----\n");
     printf("\t\t=========================\n");
     printf("\033[0m");
 
     int bookID;
     printf("\n\nEnter Book ID: ");
     scanf("%d", &bookID);
 
     switch (button_two("Delete", "Cancel"))
     {
     case 1:
         printf("\n\tDeleting book...\n");
         Sleep(1000);
         DeleteBook(bookID); // Call function to delete book
         break;
     case 2:
         ManageBooks();
         break;
     default:
         printf("\n\tInvalid choice! Please try again.\n");
         break;
     }
 
     ManageBooks(); // Return to book management menu
 }
 
 void DeleteBook(int bookID)
 {
     FILE *file = fopen("books.dat", "rb");
     FILE *tempFile = fopen("temp.dat", "wb");
 
     if (file == NULL || tempFile == NULL) {
         printf("Error opening book database.\n");
         return;
     }
 
     BackupBooks(); // Create a backup before deletion
 
     Book book;
     int found = 0;
 
     while (fread(&book, sizeof(Book), 1, file)) {
         if (book.bookID == bookID) { 
             if (book.is_borrowed) {  
                 printf("\n\tCannot delete book ID %d. It is currently borrowed.\n", bookID);
                 fclose(file);
                 fclose(tempFile);
                 remove("temp.dat");
                 return;
             }
             found = 1;
             continue; // Skip writing this book to the new file
         }
         fwrite(&book, sizeof(Book), 1, tempFile);
     }
 
     fclose(file);
     fclose(tempFile);
 
     if (found) {
         remove("books.dat");
         rename("temp.dat", "books.dat");
 
         RemoveBookFromUsers(bookID); // Ensure the book is removed from users' records
 
         printf("\n\tBook with ID %d deleted successfully.\n", bookID);
     } else {
         remove("temp.dat"); // Delete temp file if book was not found
         printf("\n\tBook with ID %d not found.\n", bookID);
     }
 
     Sleep(1000);
 }
 
 void ViewUsers()
 {
     clear_screen();
     Admin(10);
     printf("\033[33m");
     printf("\t\t=========================\n");
     printf("\t\t----- Users ----\n");
     printf("\t\t=========================\n");
     printf("\033[0m");
 
     FILE *userFile = fopen("users.dat", "rb");
     if (userFile == NULL) {
         printf("Error opening users database.\n");
         return;
     }
 
     User user;
     int index = 1;
     printf("\nList of users:\n");
     printf("--------------------------------------------\n");
     while (fread(&user, sizeof(User), 1, userFile)) {
         printf("\t %d. %s (ID: %d)\n", index++, user.username, user.id);
     }
 
     fclose(userFile);
 
     int userChoice, userID;
 
     printf("\n\tSelect an option:\n");
     printf("\t1️. Enter user ID to view details\n");
     printf("\t2. Enter user ID to delete\n");
     printf("\t3. AdminPortal\n");
 
     printf("\n>: ");
     scanf("%d", &userChoice);
 
     switch (userChoice)
     {
     case 1:
         printf("\n\tEnter user ID to view details: ");
         scanf("%d", &userID);
         ViewUser(userID); // Function to view user details
         break;
 
     case 2:
         printf("\nEnter user ID to delete: ");
         scanf("%d", &userID);
         DeleteUser(userID); // Function to delete user
         break;
     
     case 3: // Admin Portal
         AdminPortal();
         break;
 
     default:
         printf("\nInvalid choice! Please enter 1 or 2.\n");
         ManageUser(); // Recursively call again if input is wrong
         break;
     }
 
     // View the selected user's details
     ViewUser(userChoice);
 }
 
 void ViewUser(int userID)
 {
     clear_screen();
     Admin(10);
     printf("\033[33m");
     printf("\t\t=========================\n");
     printf("\t\t----- User Details -----\n");
     printf("\t\t=========================\n");
     printf("\033[0m");
 
     FILE *userFile = fopen("users.dat", "rb");
     FILE *bookFile = fopen("books.dat", "rb");
     if (userFile == NULL || bookFile == NULL) {
         printf("Error opening database files.\n");
         return;
     }
 
     User user;
     Book book;
     int userFound = 0;
 
     // Find the user
     while (fread(&user, sizeof(User), 1, userFile)) {
         if (user.id == userID) {
             userFound = 1;
             printf("\nUser Name: %s\n", user.username);
             printf("User Email: %s\n", user.email);
             printf("Books Borrowed: %d\n", user.borrowed_count);
             break;
         }
     }
 
     if (!userFound) {
         printf("\nUser not found.\n");
         fclose(userFile);
         fclose(bookFile);
         AdminMenue (); 
         return;
     }
 
     // Display borrowed books
     printf("\nBooks Borrowed:\n");
     printf("ID\tTitle\t\tAuthor\t\tStatus\n");
     printf("----------------------------------------------\n");
 
     for (int i = 0; i < user.borrowed_count; i++) {
         rewind(bookFile);
         while (fread(&book, sizeof(Book), 1, bookFile)) {
             if (book.bookID == user.borrowed_books[i]) {
                 const char *status = book.is_borrowed ? "Borrowed" : "Returned";
                 printf("%d\t%s\t%s\t\t%s\n", book.bookID, book.title, book.author, status);
                 break;
             }
         }
     }
 
     fclose(userFile);
     fclose(bookFile);
 
     switch (button_two("Done", "View All Users")) {
     case 1:
         Sleep(1000);
         AdminPortal();
         break;
     case 2:
         Sleep(1000);
         ViewUsers();
         break;
     default:
         printf("\n\tInvalid choice! Please try again.\n");
         break;
     }
 }
 
 void DeleteUser(int userID)
 {
     loading(1);
     FILE *file = fopen("users.dat", "rb");
     FILE *tempFile = fopen("temp.dat", "wb");
 
     if (file == NULL || tempFile == NULL)
     {
         printf("Error opening user database.\n");
         return;
     }
 
     User user;
     int found = 0;
 
     while (fread(&user, sizeof(User), 1, file))
     {
         if (user.id == userID)
         {   
             found = 1;  // Mark that we found the user
             continue;   // Skip writing this user (delete it)
         }
         fwrite(&user, sizeof(User), 1, tempFile);
     }
 
     fclose(file);
     fclose(tempFile);
 
     remove("users.dat");       // Delete old file
     rename("temp.dat", "users.dat");  // Rename new file to original
 
     if (found)
     {
         printf("\n✅ User with ID %d deleted successfully.\n", userID);
     }
     else
     {
         printf("\n❌ User with ID %d not found.\n", userID);
     }
 
     Sleep(1000);
     AdminPortal();  // Return to Admin Panel
 }
 
 
 void Library()
 {
     clear_screen();
     Admin(10);
     printf("\033[33m");
     printf("\t\t=========================\n");
     printf("\t\t-----Current Library V %s ----\n", VERSION);
     printf("\t\t=========================\n");
     printf("\033[0m");
 
     printf("\n\n");
 
     FILE *userFile = fopen("users.dat", "rb");
     FILE *bookFile = fopen("books.dat", "rb");
 
     if (userFile == NULL || bookFile == NULL)
     {
         printf("Error opening database files.\n");
         return;
     }
 
     User user;
     Book book;
     int recordsFound = 0;
 
     int totalBooks = 0, totalUsers = 0, borrowedBooks = 0, availableBooks = 0;
 
     while (fread(&book, sizeof(Book), 1, bookFile))
     {
         totalBooks++;
         if (book.is_borrowed)
             borrowedBooks++;
     }
     availableBooks = totalBooks - borrowedBooks;
     rewind(bookFile);  // Reset file pointer for next read
 
     // **Count total users**
     while (fread(&user, sizeof(User), 1, userFile))
     {
         totalUsers++;
     }
     rewind(userFile);  // Reset file pointer for next read
 
     // **Display dynamically updated info**
     printf("Total Books Count : %d\n", totalBooks);
     printf("Total User Count  : %d\n", totalUsers);
     printf("Borrowed Books    : %d\n", borrowedBooks);
     printf("Available Books   : %d\n", availableBooks);
 
     printf("\n=======================================================================\n");
     printf("|   User ID   |        User Name       |   Book ID   |       Title       |   Author   |\n");
     printf("=======================================================================\n");
 
     while (fread(&user, sizeof(User), 1, userFile))
     {
         for (int i = 0; i < user.borrowed_count; i++)
         {
             rewind(bookFile);
             while (fread(&book, sizeof(Book), 1, bookFile))
             {
                 if (book.bookID == user.borrowed_books[i])
                 {
                     printf("| %10d | %-22s | %9d | %-15s | %-10s |\n",
                            user.id, user.username, book.bookID, book.title, book.author);
                     recordsFound = 1;
                     break;
                 }
             }
         }
     }
 
     if (!recordsFound)
     {
         printf("|                            No borrowed books found!                         |\n");
     }
 
     printf("=======================================================================\n");
 
     fclose(userFile);
     fclose(bookFile);
 
 
 switch (button_three("Update Version", "Admin Panel", "Logout"))
 {
 case 1:
     loading(1);
     printf("Version Number (eg. x.x.x):");
     scanf("%s", VERSION);
     loading(1);
     printf("\n\tUpdating version...\n");
     Sleep(1000);
     printf("\n\tVersion updated to %s\n", VERSION);
     Sleep(1000);
     Library();
     break;
     
 case 2:
     loading(1);
     AdminPortal();
     break;
 
 case 3:
     loading(1);
     StartMenue();
     break;
 
 default:
     printf("\n\tInvalid choice! Please try again.\n");
     Library();
     break;
 }
 }
 
 int CheckUserExists(char username[])
 {
     FILE *file = fopen("users.dat", "rb");
     if (file == NULL)
     {
         return 0;
     }
 
     User user;
     while (fread(&user, sizeof(User), 1, file))
     {
         if (strcmp(user.username, username) == 0)
         {
             fclose(file);
             return 1;
         }
     }
 
     fclose(file);
     return 0;
 }
 
 void register_user()
 {
     clear_screen();
     regiAnimation(10);
 
     printf("\033[31m");
     printf("\n\n\t\t Admin Privilege\n\n");
     printf("\033[0m");
 
     printf("---+-----+------   Register   ---+-----+------\n\n");
 
     User user;
 
     while (1)
     {
         printf("Username: ");
         scanf(" %[^\n]", user.username);
 
         if (CheckUserExists(user.username))
         {
             printf("\nUsername already exists! Please choose a different one.\n\n");
         }
         else
         {
             break;
         }
     }
 
     printf("\nEmail: ");
     scanf(" %[^\n]", user.email);
     printf("\nPassword: ");
     scanf(" %[^\n]", user.password);
 
     switch (button_two("Submit", "Back"))
     {
     case 1:
         loading(0.5);
         printf("Registering...\n");
         Sleep(1000);
         register_user_success(user);
         break;
     case 2:
         StartMenue();
         break;
     default:
         printf("\n\tInvalid choice! Please try again.\n");
         break;
     }
 
 }
 
 int GenerateUserID()
 {
     FILE *file = fopen("users.dat", "rb");
     if (file == NULL)
     {
         return 1;
     }
 
     User user;
     int lastID = 0;
     while (fread(&user, sizeof(User), 1, file))
     {
         lastID = user.id;
     }
 
     fclose(file);
     return lastID + 1; // Assign the next available ID
 }
 
 void register_user_success(User user)
 {
     clear_screen();
     regiAnimation(10);
     printf("\033[31m");
     printf("\n\n\t\t Admin Privilege\n\n");
     printf("\033[0m");
     printf("---+-----+------   Register   ---+-----+------\n\n");
 
     FILE *file = fopen("users.dat", "ab");
     if (file == NULL)
     {
         printf("Error opening user database.\n");
         return;
     }
 
     user.id = GenerateUserID(); // Assign a unique ID
     fwrite(&user, sizeof(User), 1, file);
     fclose(file);
 
     printf("User registered successfully! Your User ID: %d\n", user.id);
 
     switch (button_two("Register New", "Back"))
     {
     case 1:
         register_user();
         break;
     case 2:
         StartMenue();
         break;
     default:
         printf("\n\tInvalid choice! Please try again.\n");
         register_user_success(user);
         break;
     }
 }
 
 void ViewBooksUsr(int userID)
 {
     clear_screen();
     UserScreen(10);
 
     printf("\033[33m");
     User *user = GetUser(userID);
     if (user != NULL)
     {
         printf("\n\n\t\t%s's Profile\n", user->username);
     }
     else
     {
         printf("\n\n\t User not found!\n");
     }
 
     
     printf("\n\t\t=========================\n");
     printf("\t\t----- View All Books ----\n");
     printf("\t\t=========================\n");
     printf("\033[0m");
 
     printf("\n\n");
 
     FILE *file = fopen("books.dat", "rb");
     if (file == NULL)
     {
         printf("Error opening book database.\n");
         return;
     }
 
     Book book;
     printf("----------------------------\n");
 
     printf("\n\033[33m");
     printf("====================================================================\n");
     printf("| %-5s | %-30s | %-20s | %-10s |\n", "ID", "Title", "Author", "Status");
     printf("====================================================================\n");
     printf("\033[0m");
 
     while (fread(&book, sizeof(Book), 1, file))
     {
         printf("| %5d | %-50s | %-40s | %-10s |\n",
                book.bookID, book.title, book.author,
                book.is_borrowed ? "Borrowed" : "Available");
     }
 
     printf("====================================================================\n");
 
     fclose(file);
 
     switch (button_three("Search Books", "Borrow Books", "Back"))
     {
     case 1:
         loading(1);
         SearchBooksUsr(userID);
         break;
     case 2:
         loading(1);
         BorrowBooksUsr(userID); // for trial purpose
         break;
     case 3:
         loading(1);
         UserPortal(userID); // for trial purpose
         break;
     default:
         printf("\n\tInvalid choice! Please try again.\n");
         Sleep(0.5);
         ViewBooksUsr(userID);
         break;
     }
 }
 
 void SearchBooksUsr(int userID)
 {
     clear_screen();
     UserScreen(10);
     printf("\033[33m");
 
     User *user = GetUser(userID);
     if (user != NULL)
     {
         printf("\n\n\t\t%s's Profile\n", user->username);
     }
     else
     {
         printf("\n\n\t User not found!\n");
     }
 
     printf("\t\t=========================\n");
     printf("\t\t----- Search Books ----\n");
     printf("\t\t=========================\n");
     printf("\033[0m");
 
     int bookID;
     printf("\n\nEnter Book ID: ");
     scanf("%d", &bookID);
 
     Book *book = SearchBookByID(bookID);
 
     if (book == NULL)
     {
         printf("\nBook with ID %d not found.\n", bookID);
         Sleep(1000);
         UserPortal(userID); //modified - for trial purpose
         return;
     }
 
     printf("\033[33m");
     printf("\n\tBook Found: %s by %s\n", book->title, book->author);
     printf("\033[0m");
     switch (button_two("Borrow", "Back"))
     {
     case 1:
         Sleep(1000);
         BorrowBook(userID , bookID);
         break;
     case 2:
         UserPortal(userID); // for trial purpose
         break;
     default:
         printf("\n\tInvalid choice! Please try again.\n");
         break;
     }
 }
 
 Book *SearchBookByID(int bookID)
 {
     FILE *file = fopen("books.dat", "rb");
     if (file == NULL)
     {
         printf("Error opening book database.\n");
         return NULL;
     }
 
     static Book book;
     while (fread(&book, sizeof(Book), 1, file))
     {
         if (book.bookID == bookID)
         {
             fclose(file);
             return &book;
         }
     }
 
     fclose(file);
     printf("Book with ID %d not found.\n", bookID);
     return NULL;
 }
 
 void BorrowBooksUsr(int userID)
 {
     clear_screen();
     UserScreen(10);
     printf("\033[33m");
 
     User *user = GetUser(userID);
     if (user != NULL)
     {
         printf("\n\n\t\t%s's Profile\n", user->username);
     }
     else
     {
         printf("\n\n\t User not found!\n");
     }
 
     printf("\t\t=========================\n");
     printf("\t\t----- Borrow Books ----\n");
     printf("\t\t=========================\n");
     printf("\033[0m");
 
     int bookID;
     printf("\n\nEnter Book ID: ");
     scanf("%d", &bookID);
 
     switch (button_two("Borrow", "Cancel"))
     {
     case 1:
         printf("\n\tProcessing book borrowing...\n");
         Sleep(1000);
         BorrowBook(userID, bookID);
         break;
     case 2:
         UserPortal(userID); // for trial purpose
         break;
     default:
         printf("\n\tInvalid choice! Please try again.\n");
         BorrowBooksUsr(userID);
         break;
     }
 }
 
 void BorrowBook(int userID, int bookID)
 {
     FILE *bookFile = fopen("books.dat", "rb+");
     FILE *userFile = fopen("users.dat", "rb+");
 
     if (bookFile == NULL || userFile == NULL)
     {
         printf("Error opening database files.\n");
         UserPortal(userID);
         return;
     }
 
     Book book;
     User user;
     int bookFound = 0, userFound = 0;
 
     // Locate the book
     while (fread(&book, sizeof(Book), 1, bookFile))
     {
         if (book.bookID == bookID)
         {
             bookFound = 1;
             if (book.is_borrowed)
             {
                 printf("\n\tBook is already borrowed.\n");
                 fclose(bookFile);
                 fclose(userFile);
                 return;
             }
             break;
         }
     }
 
     // Locate the user
     while (fread(&user, sizeof(User), 1, userFile))
     {
         if (user.id == userID)
         {
             userFound = 1;
             break;
         }
     }
 
     if (!bookFound)
     {
         printf("\n\tBook with ID %d not found.\n", bookID);
     }
     else if (!userFound)
     {
         printf("\n\tUser with ID %d not found.\n", userID);
     }
     else
     {
         // Mark the book as borrowed
         book.is_borrowed = 1;
         fseek(bookFile, -sizeof(Book), SEEK_CUR);
         fwrite(&book, sizeof(Book), 1, bookFile);
 
         // Update user's borrowed books list
         user.borrowed_books[user.borrowed_count++] = bookID;
         fseek(userFile, -sizeof(User), SEEK_CUR);
         fwrite(&user, sizeof(User), 1, userFile);
 
         printf("\n\tWait Processing");
         fflush(stdout);
         Sleep(0.5);
 
         printf("\n\t\rBook (ID: %d) borrowed by %s successfully!\n", bookID, userID);
         Sleep(0.5);
         UserPortal(userID);
     }
 
     fclose(bookFile);
     fclose(userFile);
 }
 
 void ReturnBooks(int userID)
 {
     clear_screen();
     UserScreen(10);
     printf("\033[33m");
 
     User *user = GetUser(userID);
     if (user != NULL)
     {
         printf("\n\n\t\t%s's Profile\n", user->username);
     }
     else
     {
         printf("\n\n\t User not found!\n");
     }
 
 
     printf("\t\t=========================\n");
     printf("\t\t----- Return Books ----\n");
     printf("\t\t=========================\n");
     printf("\033[0m");
 
     int bookID;
     printf("\n\nEnter Book ID: ");
     scanf("%d", &bookID);
 
     switch (button_two("Return", "Cancel"))
     {
     case 1:
         printf("\n\tProcessing book return...\n");
         Sleep(1000);
         ReturnBook(userID, bookID);
         
         break;
     case 2:
         UserPortal(userID); // for trial purpose
         break;
     default:
         printf("\n\tInvalid choice! Please try again.\n");
         ReturnBooks(userID);
         break;
     }
 }
 
 void ReturnBook(int userID, int bookID)
 {
     FILE *bookFile = fopen("books.dat", "rb+");
     FILE *userFile = fopen("users.dat", "rb+");
 
     if (bookFile == NULL || userFile == NULL)
     {
         printf("\n\tError opening database files.\n");
         return;
     }
 
     Book book;
     User user;
     int bookFound = 0, userFound = 0, bookInUserRecord = 0;
 
     // Locate the book
     while (fread(&book, sizeof(Book), 1, bookFile))
     {
         if (book.bookID == bookID)
         {
             bookFound = 1;
             break;
         }
     }
 
     // Locate the user
     while (fread(&user, sizeof(User), 1, userFile))
     {
         if (user.id == userID)
         {
             userFound = 1;
             // Check if the user has borrowed this book
             for (int i = 0; i < user.borrowed_count; i++)
             {
                 if (user.borrowed_books[i] == bookID)
                 {
                     bookInUserRecord = 1;
                     user.borrowed_books[i] = -1; // Mark as returned
                     user.borrowed_count--;
                     break;
                 }
             }
             break;
         }
     }
 
     if (!bookFound)
     {
         printf("\n\tBook with ID %d not found.\n", bookID);
         Sleep(1000);
         UserPortal(userID);
     }
     else if (!userFound)
     {
         printf("\n\tUser with ID %d not found.\n", userID);
         Sleep(1000);
         UserPortal(userID);
     }
     else if (!bookInUserRecord)
     {
         printf("\n\tUser did not borrow this book.\n");
         Sleep(1000);
         UserPortal(userID);
     }
     else
     {
         // Mark the book as available
         book.is_borrowed = 0;
         fseek(bookFile, -sizeof(Book), SEEK_CUR);
         fwrite(&book, sizeof(Book), 1, bookFile);
 
         // Update user's record
         fseek(userFile, -sizeof(User), SEEK_CUR);
         fwrite(&user, sizeof(User), 1, userFile);
 
         printf("\n\tWait Processing");
         fflush(stdout);
         Sleep(0.5);
         printf("\n\t\rBook (ID: %d) returned successfully!\n", bookID);
         Sleep(0.5);
         UserPortal(userID);
     }
 
     fclose(bookFile);
     fclose(userFile);
 }
 
 void BooksHistoryUsr(int userID)
 {
     clear_screen();
     UserScreen(10);
     printf("\033[33m");
 
     User *userPtr = GetUser(userID);
     if (userPtr != NULL)
     {
         printf("\n\n\t\t%s's Profile\n", userPtr->username);
     }
     else
     {
         printf("\n\n\t User not found!\n");
     }
 
     printf("\t\t=========================\n");
     printf("\t\t----- Books History ----\n");
     printf("\t\t=========================\n");
     printf("\033[0m");
 
     FILE *userFile = fopen("users.dat", "rb");
     FILE *bookFile = fopen("books.dat", "rb");
 
     if (userFile == NULL || bookFile == NULL)
     {
         printf("Error opening database files.\n");
         return;
     }
 
     User user;
     Book book;
     int userFound = 0;
 
     // Find the user
     while (fread(&user, sizeof(User), 1, userFile))
     {
         if (user.id == userID)
         {
             userFound = 1;
             break;
         }
     }
 
     if (!userFound)
     {
         printf("\n\tUser with ID %d not found.\n", userID);
         fclose(userFile);
         fclose(bookFile);
         return;
     }
 
     if (user.borrowed_count == 0)
     {
         printf("\n\tUser ID %d has no borrowed books.\n", userID);
         fclose(userFile);
         fclose(bookFile);
         return;
     }
 
     // Display table header
     printf("\n\tBooks Borrowed by User ID %d - %s\n", user.id, user.username);
     printf("\t=======================================================================\n");
     printf("\t|   Book ID   |       Title        |       Author        |\n");
     printf("\t=======================================================================\n");
 
     // Print borrowed books
     for (int i = 0; i < user.borrowed_count; i++)
     {
         rewind(bookFile);
         while (fread(&book, sizeof(Book), 1, bookFile))
         {
             if (book.bookID == user.borrowed_books[i])
             {
                 printf("\t| %10d | %-18s | %-18s |\n", book.bookID, book.title, book.author);
                 break;
             }
         }
     }
 
     // Table footer
     printf("\t=======================================================================\n");
 
     fclose(userFile);
     fclose(bookFile);
 
     printf("\n\n");
 
     switch (button_two("Done", "Back"))
     {
     case 1:
         loading(1);
         UserPortal(userID); // for trial purpose
         break;
     case 2:
         loading(1);
         UserPortal(userID); // for trial purpose
         break;
     default:
         printf("\n\tInvalid choice! Please try again.\n");
         loading(1);
         BooksHistoryUsr(userID);
         break;
     }
 }
 
 void LogoutUsr()
 {
     printf("\n\nLogging out...\n");
     Sleep(1000);
     StartMenue();
 }
 
 void UserPortal(int userID)
 {
     clear_screen();
     UserScreen(10);
 
     User *user = GetUser(userID);
     if (user != NULL)
     {
         printf("\n\n\t Welcome, %s\n", user->username);
     }
     else
     {
         printf("\n\n\t User not found!\n");
     }
 
     printf("\t_____________________________\n\n");
     UserMenue(userID);
 }
 
 
 void ResetBooks()
 {
     loading(1);
     FILE *file = fopen("books.dat", "wb"); // Open in write mode to overwrite
     if (file == NULL)
     {
         printf("Error resetting books database.\n");
         return;
     }
     fclose(file);
     printf("\n\tAll books have been deleted. Library is empty now.\n");
     Sleep(1000);
     AdminPortal();
 }
 
 // Function to reset the users file
 void ResetUsers()
 {
     loading(1);
     FILE *file = fopen("users.dat", "wb"); // Open in write mode to overwrite
     if (file == NULL)
     {
         printf("Error resetting users database.\n");
         return;
     }
     fclose(file);
     printf("\n\tAll users have been deleted. No users exist now.\n");
 
     Sleep(1000);
     AdminPortal();
 }
 
 // Function to reset everything (books + users)
 void ResetLibrary()
 {
     loading(1);
     printf("\033[31m");
     printf("\n\tAre you sure you want to reset the library? This will delete ALL data! (Y/N): ");
     printf("\033[0m");
     char confirm;
     scanf(" %c", &confirm);
 
     if (confirm == 'Y' || confirm == 'y')
     {
         loading(1);
 
         printf("\033[31m");
         loading(2);
         printf("\033[0m");
 
         ResetBooks();
         ResetUsers();
         printf("\033[32m");
         
         printf("\n\tLibrary has been fully reset. All books and users are removed.\n\n");
         printf("\033[0m"); 
     }
     else
     {
         printf("Reset operation canceled.\n");
     }
     Sleep(1000);
     loading(1);
     AdminPortal();
 }
 
 
 
 void BackupBooks() {
     printf("BackupBooks function is not implemented yet.\n");
 }
 
 
 void RemoveBookFromUsers(int bookID) {
     printf("RemoveBookFromUsers function is not implemented yet.\n");
 }
 
 
 void ManageUser() {
     printf("ManageUser function is not implemented yet.\n");
 }
 
 
 void BorrowSuccess(int UserID , int bookID) {
     printf("under development");
 }
 
 
 void ReturnSuccess(int userID) {
     printf("ReturnSuccess function is not implemented yet for user %d.\n", userID);
 }
 
 
 User* GetUser(int userID) {
     static User user;  // Static to persist data after function returns
     FILE *file = fopen("users.dat", "rb");
 
     if (file == NULL) {
         printf("Error opening users database.\n");
         return NULL;
     }
 
     while (fread(&user, sizeof(User), 1, file)) {
         if (user.id == userID) {
             fclose(file);
             return &user;  // Return pointer to the found user
         }
     }
 
     fclose(file);
     return NULL;  // Return NULL if user not found
 }
 
 void irshad_name(int a)
 {
     printf("\n\t\t\tby\n");
     int space = 6; // Adjust spacing for alignment
     const char *art[] = {
         "                                                  ",
         "  _____   _____     _____   _    _              _____  ",
         " |_   _| |  __ \\   / ____| | |  | |     /\\     |  __ \\ ",
         "   | |   | |__) | | (___   | |__| |    /  \\    | |  | |",
         "   | |   |  _  /   \\___ \\  |  __  |   / /\\ \\   | |  | |",
         "  _| |_  | | \\ \\   ____) | | |  | |  / ____ \\  | |__| |",
         " |_____| |_|  \\_\\ |_____/  |_|  |_| /_/    \\_\\ |_____/  ",
         "                                                  "};
 
     int num_lines = sizeof(art) / sizeof(art[0]);
 
     do
     {
         for (int i = 0; i < num_lines; i++)
         {
             printf("%*s", space, ""); // Add leading spaces for centering
             SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
             printf("%s\n", art[i]);
         }
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Reset color
         Sleep(a);
 
     } while (0);
 }
 
 void Library_guest()
 {
     clear_screen();
     welcome(20);
     irshad_name(30);
     printf("\n\n\n");
     printf("\033[33m");
     printf("\t\t==================================\n");
     printf("\t\t-----Current Library V %s ----\n", VERSION);
     printf("\t\t==================================\n");
     printf("\033[0m");
 
     printf("\n\n");
 
     FILE *bookFile = fopen("books.dat", "rb");
 
     if (bookFile == NULL)
     {
         printf("Error opening book database file.\n");
         return;
     }
 
     Book book;
     int totalBooks = 0, borrowedBooks = 0, availableBooks = 0;
 
     // Calculate total, borrowed, and available books
     while (fread(&book, sizeof(Book), 1, bookFile))
     {
         totalBooks++;
         if (book.is_borrowed)
             borrowedBooks++;
     }
     availableBooks = totalBooks - borrowedBooks;
     rewind(bookFile);  // Reset file pointer for next read
 
     // Display the statistics for the guest viewer
     printf("Total Books Count   : %d\n", totalBooks);
     printf("Borrowed Books      : %d\n", borrowedBooks);
     printf("Available Books     : %d\n", availableBooks);
 
     printf("\n=======================================================================\n");
     printf("|   Book ID   |        Title       |   Author   |\n");
     printf("=======================================================================\n");
 
     // Display the list of all books with book name and author
     while (fread(&book, sizeof(Book), 1, bookFile))
     {
         printf("| %9d | %-15s | %-10s |\n", book.bookID, book.title, book.author);
     }
 
     printf("=======================================================================\n");
 
     // Display the login prompt message
     printf("\nLogin to access more features of LMS.\n");
 
     fclose(bookFile);
 
     // Provide options for the guest user (e.g., navigate back to the menu or logout)
     switch (button_two("Login", "Exit"))
     {
     case 1:
         loading(1);
         login(); // Assuming you have a Login function to handle guest login
         break;
     case 2:
         loading(1);
         StartMenue();
         break;
     default:
         printf("\n\tInvalid choice! Please try again.\n");
         Library_guest();
         break;
     }
 }
 