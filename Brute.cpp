#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <fstream>

using namespace std;

void clearTerminal(){ //Clears the terminal
    system("printf '\\033[H\\033[2J'"); //ASCII Shortcut for clearing the terminal with scrollback might be changed later
};

void timeSleepOne(){
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds
    sleep_until(system_clock::now() + seconds(1));
}

void sshFileHandling(){ //saves the server credentials in a txt file 
    string localip;
    string alias;
    cout << "enter the server local ip";
    cin >> localip;
    cout << "enter the server's alias";
    cin >> alias;
    fstream sshFile; //in is for reading, and app is for appending, out is for writing (overwriting) 
    sshFile.open("serverlist.txt", std::ios::in | std::ios::app );
    sshFile << localip << endl << alias << endl; 
    sshFile.close();
}

void sshFunction(){

}

void sftpFunction(){

}

void fetchTime(){
    time_t timestamp;
    time(&timestamp);
    string x = ctime(&timestamp);
    cout << x;
}

void mainMenu(){ //This includes all the tui for the main menu and some other stuff
    int mainMenuAnswer;    
    
    string title = R"( 
       __            __
      / /  ______ __/ /____ 
     / _ \/ __/ // / __/ -_)
    /_.__/_/  \_,_/\__/\__/ 
    )";

    fetchTime();
    cout << "=================================\n";
    cout << title << endl;
    cout << "=================================\n";
    cout << "[1.] [ SSH  ]\n";
    cout << "[2.] [ SFTP ]\n";
    cout << "[3.] [ Exit ]\n";
    cout << "=================================\n";
    cout << "[1-3] ";
    cin >> mainMenuAnswer;
    
    switch (mainMenuAnswer){
        
        case 1:
            clearTerminal();
            cout << "Opening SSH";
            sshFunction();
            break; 
        
        case 2:
            clearTerminal();
            cout << "Opening SFTP";
            sftpFunction();
            break; 

        case 3:
            clearTerminal();
            cout << "Exiting\n";
            timeSleepOne();
            clearTerminal();
            exit;
            break;
        
        default:
            clearTerminal();
            cout << "Invalid Input Try Again";
            timeSleepOne();
            clearTerminal();
            mainMenu();
            break;
    } 

};

int main(){ //Main script
    clearTerminal();
    mainMenu();
};
