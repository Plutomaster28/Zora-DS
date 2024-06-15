#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <filesystem>
#include <fstream>
#include <cstdlib> // For system()
#include <ctime>

namespace fs = std::filesystem;

// Function to split a string into tokens
std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Get the path to the home directory
fs::path getHomeDirectory() {
    return fs::current_path() / "Zora";
}

// Function to display system information
void displaySystemInfo() {
    // Operating system version
#ifdef _WIN32
    std::cout << "\nOperating System: Windows" << std::endl;
#elif __APPLE__
    std::cout << "Operating System: macOS" << std::endl;
#elif __linux__
    std::cout << "Operating System: Linux" << std::endl;
#else
    std::cout << "Operating System: Something from Narnia I have ZERO clue what the hell this is" << std::endl;
#endif

    // Hardware specifications
    std::ifstream cpuinfo("/proc/cpuinfo");
    std::string line;
    if (cpuinfo.is_open()) {
        while (std::getline(cpuinfo, line)) {
            if (line.find("model name") != std::string::npos) {
                std::cout << "CPU: " << line.substr(line.find(":") + 2) << std::endl;
                break;
            }
        }
        cpuinfo.close();
    }
    else {
        std::cout << "CPU: Why it's the silly processor of course! >w<" << std::endl;
    }

    // Memory information
    std::ifstream meminfo("/proc/meminfo");
    if (meminfo.is_open()) {
        while (std::getline(meminfo, line)) {
            if (line.find("MemTotal") != std::string::npos) {
                std::cout << "Memory: " << line.substr(line.find(":") + 2) << std::endl;
                break;
            }
        }
        meminfo.close();
    }
    else {
        std::cout << "Memory: Infinite lmfao" << std::endl;
    }

    std::cout << "\n(C)Zora system is proprietary software. All Rights Reserved." << std::endl;
    std::cout << "1985 Meisei\n" << std::endl;

    std::cout << "\nCredits: \n" << std::endl;
    std::cout << R"(
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++*************+++++++++++++++++++++++++++++++++++++++
+++++++++++++++++++++++++++++++++++++++++++*#%%@@@@@@@@@@@@@@@@%%#**++++++++++++++++++++++++++++++++
+++++++++++++++++++++++++++++++++++++++++*%@@@@@@@@@@@@@@@@@@@@@@@@@%#*+++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++*%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#*++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++*%@@@@@@@%#**%@@@@@@%@@@@@@@@@@@@@@@%*++++++++++++++++++++++++
+++++++++++++++++++++++++++++++++++++*%@@@@@%%%@@%#*%@@%%%*#@@@@@@@@@@@@@@@@#+++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++*%@@@@#*#%@@@@%#**%@@@%%@@@@@@@@@@@@@%%@@%*+++++++++++++++++++++
+++++++++++++++++++++++++++++++++++*%@@@@@@@%%**%%%%@@%%%@#%@@@@@@@@@@@@%#%%@@%*++++++++++++++++++++
++++++++++++++++*#%%%%%%***+++++++*%@@@@@@@@@@@%%%@@@@@@#*#%@@@@@@@@@@@@##%*@@@%*+++++++++++++++++++
+++++++++++++*%@@@@@@@@@@@@@@%%**+*#******##%%@@@@@@@@@@@%%@@@@@@@@@@@@##%*%@@@@%**#####**++++++++++
++++++++++++%@@@@@@@@@@@@@@@@@@@@@%%%#*+======++***#%%@@@@@@@@@@@@@@@@##%*%@@@@@@%****##%%#**+++++++
+++++++++++#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%%**+++++***#@@@@@@@@@@@%#%#%@@@@@@@@@@#****#%%#*++++++
+++++++++++%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%#*++*#%%%@@@@@@%*%#%@@@@@@@@%**%%*****##*++++++
+++++++++++*@@@@@@@@@@@@@%%%%%%%%%%%%%%@@@@@@@@@@@@@@@@@@@@%%#*#%@@%*%#%@@@@@@@@@%*++*%#****#*++++++
++++++++*+++#@@@@@@@@@@@@%*+=================+*%@@@@@@@@@@@@@@@%%#%@@%%@@@@@@@@@@#++++*#%*****++++++
*+*+*+*++***#@@%%******+=+*++*===================+#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%*++++++*@****++++++
+*+*++****+==============**+=========================*%@@#**+====+*%@@@@@@@@@@@@#+*+*+*++##*##+*+*+*
++++*#*==============+**==================================**+=========+*%@@@@@@%*+++++++*+%@%*++++++
*+*+*#%+==========*#+=====================================%@@@%*===========+*#%%%#**+*+++**#**+*+*+*
+*+***%#+======*%%%*=================================+%===%@%%@*=================+*%%%**+*+*+*+*++*+
*+*+***%#===*%%%%%%%*============+#%*===============*#+===#@@@%@*====================+#@#*++*+++*+++
**+*+*+*+=#%%%%%%%%%%%*+==++*#%%%%%%#============+%%#=======*@%*=============++++**#%%*%%*+*+**+*+*+
*****+***%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*======+#%%%*======================*%%%%%%%%%@##%***+*+*+**+*        <--- This is Pluto, the creator of Zora!
+*+*+***%%%%%%%%%%%%%%%%%%%%%%%%%%%%%@%%%%%%%%%%#*+====================#@@@@@%%%%%%%+##**+******+**+                If you enjoyed Zora consider maybe joining our discord, it's always open!
********#%%%%%%%%%%%%%%%%%%%%%%%%%##%@%%%%%%%##*+======================#@%%%%%%%%%**#**+**+*+*+**+**                                                          https://discord.gg/gJeFWV63rU
*********%@%%%%%%%%%%%%%%%%%%%%#####%%%%%##**+==============**==========#@%%***#**#******+**+**+**+*        (Btw the system specs are a bit above just scroll up, I'll fix that sometime in the future)
**********%@%%%%%%%%%%%%@@@%%%##**####***+=================*#============+===+*#********************        Both 100% Organic and in C++!
***********%@%%%%%%%%%%%%%%%%#*+==++===============##=====*%*===========##*%%@%*********************            :3
*************%%%%%%%%%%%%%%%*=====@#===============#%+====%@*===========#@###@**********************
***************%%%%%%%%%%%%*======%%===============+%*===+%%#+========*@%###%@@%%%#*****************        
*****************%@%%%%%%%#=======+%*===============#+===+@%%#+=======*%%#######%#******************
*****************#%%%%%%%%*================++==**========+%%%%%*+=====*@%###%%**********************
*****************%%%%%%%%@%*===========*##*+*#*===========%@%%%%%%%**#%@######%%#*******************
***************#%%%%%*%@%%%@%%*++=================+****===*@%%%%%%%%%%@%##%%%##%#*******************
*************#%%%#***%@%%%%%%%%%%%%%%%%%%%%%%%%%%@%**+=====*@%%%%%%%%%@%******#*********************
*************#*******@%%%%%%%%%%%#***************#%+========*%@%%%%%%%@%****************************
********************#@%%%%%%%%%%@%***************%*=========*%@@@%%%%%@@%***************************
********************#@%%%%%%%%%%@%**************%@%*======*%@@@@@@@@@@@@@@#*************************
*********************%@%%%%%%%%%@#*************#@@@@%##%%@@@@@@@@@@@@@@@@@@%*====+******************
**********************%@%%%%%%%%@%*************@@@@%*+#%@@@@@@@@@@@@@@@@@@@@*======+********#*******
***********************#%@@%%%%%@%************%@@@#==+*#%@@@@@@@@@@@@@@@@@@*=======+++=======+*#****
**************************#%%@@%@@***********#@@@%****%%%@@@@@@@@@@@@@@@@@%*==================+*#***
******************************#%%%***********@@@@@@#*#@@@@%%%%@@@%%@@@@@@%*====================*****
********************************************%@@@@%*+#@@%%%%%%%%%%#**#%@@@#====================+*#***
*******************************************#@@@@#==+%@%%%%%%%%%%%%%%**#@@#======================*#**
*******************************************@@@@@*=+#@%%%%@%%%%%%@%%%%%#%@@*=====***+============+***



)";
}

// Display the current working directory
void printCurrentDirectory() {
    std::cout << fs::current_path().string() << std::endl;
}

// Change the current working directory
void changeDirectory(const std::string& path) {
    fs::path newPath = path;
    if (!newPath.is_absolute()) {
        newPath = getHomeDirectory() / newPath;
    }
    try {
        fs::current_path(newPath);
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

// List the contents of the current directory
void listDirectory() {
    for (const auto& entry : fs::directory_iterator(fs::current_path())) {
        std::cout << entry.path().filename() << std::endl;
    }
}

// Create a new directory
void createDirectory(const std::string& name) {
    try {
        fs::create_directory(name);
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

// Remove a directory
void removeDirectory(const std::string& name) {
    try {
        fs::remove(name);
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

// Create a new file
void createFile(const std::string& name) {
    std::ofstream file(name);
    if (!file.is_open()) {
        std::cout << "Error: Unable to create file." << std::endl;
    }
    else {
        std::cout << "File created: " << name << std::endl;
    }
}

// Remove a file
void removeFile(const std::string& name) {
    try {
        fs::remove(name);
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

// Copy a file
void copyFile(const std::string& source, const std::string& destination) {
    try {
        fs::copy(source, destination, fs::copy_options::overwrite_existing);
        std::cout << "File copied: " << source << " -> " << destination << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

// Move a file
void moveFile(const std::string& source, const std::string& destination) {
    try {
        fs::rename(source, destination);
        std::cout << "File moved: " << source << " -> " << destination << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

// Rename a file
void renameFile(const std::string& currentName, const std::string& newName) {
    try {
        fs::rename(currentName, newName);
        std::cout << "File renamed: " << currentName << " -> " << newName << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

// Search for files matching a pattern
void searchFiles(const std::string& pattern) {
    try {
        for (const auto& entry : fs::recursive_directory_iterator(fs::current_path())) {
            if (entry.is_regular_file() && entry.path().filename().string().find(pattern) != std::string::npos) {
                std::cout << entry.path().filename() << std::endl;
            }
        }
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

// Function to open a text file in the text editor
void openTextFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    }
    else {
        std::cout << "Error: Unable to open file." << std::endl;
    }
}

// Function to save text to a file
void saveTextToFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << content;
        file.close();
        std::cout << "File saved: " << filename << std::endl;
    }
    else {
        std::cout << "Error: Unable to save file." << std::endl;
    }
}

// Function to edit a text file
void editTextFile(const std::string& filename) {
    std::string content;
    std::cout << "Enter text (type 'EOF' on a new line to finish):" << std::endl;
    std::string line;
    while (std::getline(std::cin, line) && line != "EOF") {
        content += line + "\n";
    }
    saveTextToFile(filename, content);
}

// Run an external program or command
void runProgram(const std::string& program) {
    int result = std::system(program.c_str());
    if (result == 0) {
        std::cout << "Program executed successfully." << std::endl;
    }
    else {
        std::cout << "Error: Failed to execute program." << std::endl;
    }
}

// Function to display the current date
void displayDate() {
    time_t now = time(0);
    tm timeinfo;
    if (localtime_s(&timeinfo, &now) == 0) {
        std::cout << "Current Date: " << (timeinfo.tm_year + 1900) << '-'
            << (timeinfo.tm_mon + 1) << '-'
            << timeinfo.tm_mday << std::endl;
    }
    else {
        std::cout << "Error: Unable to get current date." << std::endl;
    }
}

// Function to display the current time
void displayTime() {
    time_t now = time(0);
    tm timeinfo;
    if (localtime_s(&timeinfo, &now) == 0) {
        std::cout << "Current Time: " << timeinfo.tm_hour << ":"
            << timeinfo.tm_min << ":"
            << timeinfo.tm_sec << std::endl;
    }
    else {
        std::cout << "Error: Unable to get current time." << std::endl;
    }
}

// Function to clear the screen
void clearScreen() {
#ifdef _WIN32
    std::system("cls");
#else
    // Assume POSIX compliant system
    std::system("clear");
#endif
}

// Process command input
void processCommand(const std::string& command) {
    std::vector<std::string> tokens = split(command, ' ');

    if (tokens.empty()) {
        std::cout << "Error: Empty command." << std::endl;
        return;
    }

    std::string cmd = tokens[0];
    std::vector<std::string> args(tokens.begin() + 1, tokens.end());

    if (cmd == "exit") {
        std::cout << "Exiting..." << std::endl;
    }
    else if (cmd == "sysinfo") {
        displaySystemInfo();
    }
    else if (cmd == "pwd") {
        printCurrentDirectory();
    }
    else if (cmd == "ls") {
        listDirectory();
    }
    else if (cmd == "cd") {
        if (args.empty()) {
            changeDirectory(getHomeDirectory().string());
        }
        else {
            changeDirectory(args[0]);
        }
    }
    else if (cmd == "mkdir") {
        if (args.empty()) {
            std::cout << "Error: Missing directory name." << std::endl;
        }
        else {
            createDirectory(args[0]);
        }
    }
    else if (cmd == "rmdir") {
        if (args.empty()) {
            std::cout << "Error: Missing directory name." << std::endl;
        }
        else {
            removeDirectory(args[0]);
        }
    }
    else if (cmd == "touch") {
        if (args.empty()) {
            std::cout << "Error: Missing file name." << std::endl;
        }
        else {
            createFile(args[0]);
        }
    }
    else if (cmd == "rm") {
        if (args.empty()) {
            std::cout << "Error: Missing file name." << std::endl;
        }
        else {
            removeFile(args[0]);
        }
    }
    else if (cmd == "cp") {
        if (args.size() < 2) {
            std::cout << "Error: Missing source or destination file." << std::endl;
        }
        else {
            copyFile(args[0], args[1]);
        }
    }
    else if (cmd == "mv") {
        if (args.size() < 2) {
            std::cout << "Error: Missing source or destination file." << std::endl;
        }
        else {
            moveFile(args[0], args[1]);
        }
    }
    else if (cmd == "rename") {
        if (args.size() < 2) {
            std::cout << "Error: Missing current or new file name." << std::endl;
        }
        else {
            renameFile(args[0], args[1]);
        }
    }
    else if (cmd == "search") {
        if (args.empty()) {
            std::cout << "Error: Missing search pattern." << std::endl;
        }
        else {
            searchFiles(args[0]);
        }
    }
    else if (cmd == "edit") {
        if (args.empty()) {
            std::cout << "Error: Missing file name." << std::endl;
        }
        else {
            editTextFile(args[0]);
        }
    }
    else if (cmd == "run") {
        if (args.empty()) {
            std::cout << "Error: Missing program name." << std::endl;
        }
        else {
            runProgram(args[0]);
        }
    }
    else if (cmd == "calendar") {
        displayDate();
    }
    else if (cmd == "clock") {
        displayTime();
    }
    else if (cmd == "help") {
        std::cout << "\nAvailable commands:" << std::endl;
        std::cout << "exit - Quit the program" << std::endl;
        std::cout << "sysinfo - Display system information" << std::endl;
        std::cout << "pwd - Print the current working directory" << std::endl;
        std::cout << "ls - List the contents of the current directory" << std::endl;
        std::cout << "cd <directory> - Change the current working directory" << std::endl;
        std::cout << "mkdir <name> - Create a new directory" << std::endl;
        std::cout << "rmdir <name> - Remove a directory" << std::endl;
        std::cout << "touch <name> - Create a new file" << std::endl;
        std::cout << "rm <name> - Remove a file" << std::endl;
        std::cout << "cp <source> <destination> - Copy a file" << std::endl;
        std::cout << "mv <source> <destination> - Move a file" << std::endl;
        std::cout << "rename <current> <new> - Rename a file" << std::endl;
        std::cout << "search <pattern> - Search for files matching a pattern" << std::endl;
        std::cout << "edit <file> - Edit a text file" << std::endl;
        std::cout << "run <program> - Run an external program" << std::endl;
        std::cout << "calendar - Display current date" << std::endl;
        std::cout << "clock - Display current time" << std::endl;
        std::cout << "clear - Clears out the screen" << std::endl;
        std::cout << "MiyamiiQuest - Runs Miyamii Quest\n" << std::endl;
    }
    else if (cmd == "clear") {
        clearScreen();
    }
    else {
        std::cout << "Error: Unknown command '" << cmd << "'" << std::endl;
    }
}

int main() {
    // Ensure that the Zora directory exists
    fs::create_directory(getHomeDirectory());

    std::string input;

    std::cout << R"(    
                
                                 ....-+**+.        
                         ....-+********=.          
                 ....-+**************=  .......:.  
             .:-==++**************************:    
                  .     ..+*****************:      
               .:*-    ..   =*************:        
             .-++:.:-+*+.    =*********+.          
           ..:-+******-      -****************+:   
        .-***********.       =**************=.     
   .:::::::::+*****+.       :*************:        
    .****************-.    :***********=.          
     ..:::--=+**********:.+**********:             
             .********************+:::----.        
              .************************-.          
              .=********************+:             
               .******************-.               
                =**************+.                  
                -************-.                    
                -*********=..                      
                -*******:.                         
               .*****=.                            
               .***:.                              
              .+=.                                 
              ..                                   
                                                                                                                 
                                                                                                    
d88888D  .d88b.  d8888b.  .d8b.         d8888b. .d8888. 
YP  d8' .8P  Y8. 88  `8D d8' `8b        88  `8D 88'  YP 
   d8'  88    88 88oobY' 88ooo88        88   88 `8bo.   
  d8'   88    88 88`8b   88~~~88 C8888D 88   88   `Y8b. 
 d8' db `8b  d8' 88 `88. 88   88        88  .8D db   8D 
d88888P  `Y88P'  88   YD YP   YP        Y8888D' `8888Y' 
                                                        
Welcome!
                                                                                                                                                  
To get started, type "help" and press enter for the full list of available commands.    

                                                                                          
)";





    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);

        processCommand(input);

        if (input == "exit") {
            break;
        }
    }

    return 0;
}
