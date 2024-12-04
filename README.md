# Personal Diary Application

A simple command-line diary application written in C that allows users to create accounts, log in, and manage their personal diary entries.

## Project Structure

The project is organized into several files, each with a specific purpose:

1. **utils.h**
   - Contains utility macros
   - `CLEAR_SCREEN()`: Clears the terminal screen for better user interface

2. **auth.h & auth.c**
   - Handles user authentication
   - Functions:
     - `signUp()`: Allows new users to create an account
     - `login()`: Authenticates existing users

3. **entries.h & entries.c**
   - Manages diary entries
   - Functions:
     - `addEntry()`: Creates a new diary entry
     - `viewEntries()`: Shows all entries for the logged-in user
     - `deleteEntries()`: Removes all entries for the logged-in user

4. **main.c**
   - Contains the main program logic
   - Implements the menu system
   - Coordinates between authentication and entry management

## Data Storage

The application uses two text files for data storage:

- `users.txt`: Stores user credentials
- `entries.txt`: Stores diary entries

## How to Build and Run

1. Make sure you have a C compiler (GCC) installed on your system.

2. Open your terminal and navigate to the project directory.

3. Compile the project using:

    ```bash
    gcc main.c auth.c entries.c -o diary
    ```

4. Run the compiled binary:

    ```bash
    ./diary
    ```

## How the Build Process Works

1. The compiler processes each source file (.c):

    - main.c: Creates the program entry point
    - auth.c: Compiles authentication functions
    - entries.c: Compiles diary entry management functions

2. Header files (.h) are automatically included where needed

    - They provide function declarations
    - Ensure proper function calls between files

3. The linker combines all compiled objects into one executable

## Using the Application

1. When you run the program, you'll see three options:

    - Sign Up: Create a new account
    - Log In: Access your existing account
    - Exit: Close the application

2. After logging in, you can:

    - Add Entry: Create a new diary entry
    - View Entries: See all your entries
    - Delete Entries: Remove all your entries
    - Logout: Return to the main menu

## Tips for Beginners

- The application creates text files automatically if they don't exist
- Passwords are stored in plain text (not secure for real applications)
- Each user's entries are prefixed with their username

Use Ctrl+C to force-quit if needed

Happy journaling! 📝
