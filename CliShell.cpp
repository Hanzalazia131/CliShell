/*****

> wrong command

  Invalid command. type "help" for list of commands.

> help

 Following commands are available to Client CLI Shell:
 
  watchdog 
  gapcheck 
  crossbook 
  quit
 
 Type "help <command>" for more information
 
> help watchdog

 watchdog <identifier>
 watchdog *

> help gapcheck

 gapcheck <identifier>
 gapcheck *
  
> history

  help
  help watchdog
  ...


******/
/*
Step-1: Hard-coded commands.
Step-2: Load commands from file.
*/

#include <iostream>
#include <iostream>
#include <fstream>
#include <string>

class CliShell {
public:
	void Run () { 
        std::string userCommand, firstWord;
        // memset (userCommand,'', sizeof(userCommand));
        std::cout << ">";
        std::fstream MyFile ("history.txt");
        std::cin >> userCommand;
        // std::getline(std::cin,userCommand);
        std::cout << "after getline";
        while (userCommand != "quit"){
            std::cout << "in While";
            MyFile << userCommand << std::endl;
            int i = 0;
            for (; !isspace(userCommand[i]) ; i++) {
                firstWord[i] = userCommand[i];
            }
            if (firstWord == "Help"){
                std::cout << "in help";
                int x = 0;
                firstWord = "";
                for (; !isspace(userCommand[i+1]) ; i++) {
                    firstWord[x] = userCommand [i];
                    x++;
                }
                if (firstWord == "watchdog") {
                        watchDog();
                }
                else if (firstWord == "gapcheck") {
                        gapCheck();
                }
                else if (firstWord == "crossbook"){
                        crossBook();
                }
                else if (firstWord == ""){
                        commandList();
                }
                else{
                        std::cout << "Wronge sub-command\n";
                        subCommandList();
                }
            }
            else if (firstWord == "history"){
                std::string myText;
                while (getline (MyFile, myText)) {
                std::cout << myText;
                }
            }
            MyFile.close();   
        }
    }

        void watchDog () {
            std::cout << "Watchdog <Identifier> \n Watchdog *";
        }
        void gapCheck () {
            std::cout << "gapcheck <Identifier> \n gapcheck *";
        }
        void crossBook () {
            std::cout << "crossBook <Identifier> \n crossBook *";
        }
        void commandList(){
            std::cout << "Help\nHistory\n";
        }
        void subCommandList () {
            std::cout << " watchdog\n gapcheck\n crossbook";
        }

private:
	// std::unordered_map<string, string> _commands = {
    //         {"Help",""},
    //         {"Help","Watchdog"},
    //         {"Help","Gapcheck"},
    //         {"Help","CrossBook"},
    //         {"History",""}
    //     };
};

int main (){
    CliShell a;
    a.Run();
}