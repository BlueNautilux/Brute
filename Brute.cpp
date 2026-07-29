#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
// #include <fstream> server saving will be added in next release.

using namespace std;

void clearTerminal(){ //Clears the terminal
    system("printf '\\033[H\\033[2J'"); //ASCII Shortcut for clearing the terminal with scrollback might be changed later
};

void timeSleepOne(){
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds
    sleep_until(system_clock::now() + seconds(1));
}

void exitAnim(){
    string exitAnimstring = "Exiting";
    int number = 0;
    while (number < 4){
        cout << exitAnimstring << endl;
        exitAnimstring = exitAnimstring+ ".";
        timeSleepOne();
        clearTerminal();
        ++number;
    }
}

void sshFunc(int x){ //saves the server ip, user and alias in a txt file 
    string localip;
    string username;
    string alias;
    string combinedipssh;
    string exitquestion;
    
    while (1){
        clearTerminal();
        cout << "enter the server local ip: ";
        cin >> localip;
        if (localip.size() > 7 && localip.size() < 15) {
            break;
        }

        else {
            cout << "Invalid IP, please enter an ip between 7-15 characters in length\n";
            timeSleepOne();
            clearTerminal();
        }
    }
    
    cout << "enter the server username: "; //enter server username
    cin >> username;
    
    cout << "enter the servers alias: "; //enter server alias
    cin >> alias;
    clearTerminal();
    
    /*fstream sshFile; //in is for reading, and app is for appending, out is for writing (overwriting) will be fixed and added in later release
    sshFile.open("serverlist.txt", std::ios::in | std::ios::app );
    sshFile << alias << username << endl << localip << endl; 
    sshFile.close(); */
    if (x == 1) combinedipssh = "ssh " +username+ "@" +localip;
    else if (x == 2) combinedipssh = "sftp " +username+ "@" +localip;
    system(combinedipssh.c_str());
    clearTerminal();
    cout << "Would you like to quit? [Y] or [N]: ";
    cin >> exitquestion;
    while (1){

        if (exitquestion == "y" || exitquestion == "Y" ){
            exitAnim();
            break;
        
        }
        else if (exitquestion == "n" || exitquestion == "N"){
            system(combinedipssh.c_str());
            cout << "Would you like to quit? [Y] or [N]: ";
            cin >> exitquestion;
        }
        else {
            cout << "invalid answer enter [Y] or [N]: ";
            timeSleepOne();
            clearTerminal();
            cout << "Would you like to quit? [Y] or [N]: ";
            cin >> exitquestion;
        }
    }
}

void sshFunction(){ 
    int x = 1;
    sshFunc(x);
}

void sftpFunction(){
    int x = 2; 
    sshFunc(x);
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
            cout << "Opening SSH\n";
            timeSleepOne();
            clearTerminal();
            sshFunction();
            break; 
        
        case 2:
            clearTerminal();
            cout << "Opening SFTP\n";
            timeSleepOne();
            clearTerminal();
            sftpFunction();
            break; 

        case 3:
            clearTerminal();
            exitAnim();
            break;
        
        default:
            clearTerminal();
            cout << "Invalid Input Try Again\n";
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
