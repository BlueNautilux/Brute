#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>


using namespace std;

void clearTerminal(){
    system("printf '\\033[H\\033[2J'"); //ASCII Shortcut for clearing the terminal with scrollback might be changed later
};

void timeSleepOne(){
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds
    sleep_until(system_clock::now() + seconds(1));
}

void fetchTime(){
    time_t timestamp;
    time(&timestamp);
    string x = ctime(&timestamp);
    cout << x;
}

void mainMenu(){
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
            cout << "";
            break; 
        case 2:
            cout << "";
            break; 
        case 3:
            clearTerminal();
            cout << "Exiting\n";
            timeSleepOne();
            clearTerminal();
            exit;
            break;
    } 

};

int main(){
    clearTerminal();
    mainMenu();
};
