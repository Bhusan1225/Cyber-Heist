#include <iostream>
#include <vector>

using namespace std;

// Skill level
enum class SkillLevel
{
    Beginner,
    Intermediate,
    Expert
};

// Trace level
enum class TraceLevel
{
    low,
    medium,
    high
};

// Inventory items
enum class Inventory
{
    laptop,        // Basic hacking
    signalBlocker, // Helps to avoid being traced
    VPN,           // Helps to navigate in the bank
    hardDrive,

    negativeEye,   // Used for some hacking mechanism
    passwords,     // Hard drive password
              // Manipulates hacker's address
};

enum class TaskLevel
{

    Hight,
    Medium,
    Low

};

//baseclass HDD
class HDD
{
protected:
    string bankName;
    int memorySpace;
    vector<int> password;
    vector<string> folder;
    bool isConnected;
    int PlayerInput;

    //inputs
    int playerInput;
    char playerAnswer;

public:
    HDD(string name, int space, vector<int> passwords, vector<string> folders, bool checkconnection) : bankName(name), memorySpace(space), password(passwords), folder(folders), isConnected(checkconnection)
    {
        cout << " HDD is connecting..... wait\n";
    }
public:
    void connectHDD()
    {
  
        do {
            cout << "press 11 to connect the HDD.\n";
            cin >> playerInput;
            if (isConnected == true && playerInput == 11)
            {
                cout << "The client's HDD is connected to our d*vice n*w.\n";
                cout << "1)Scan Drive              : press S\n";
                scanHDD();

            }
            else
            {
                cout << "Not connected now, try again...\n";
            }
        } while (playerInput == 11);
    }

    void scanHDD()
    {
        cout << " Scanning......\n";
        cout << " Done\n";
        do {
            cout << "press 22 to access files\n";
            cin >> playerInput;
            if (isConnected == true && playerInput == 11)
            {
             cout << "2)Acess Folder       : press F\n";
               
             acessfolders();

            }
            else
            {
                cout << "Not connected now, try again...\n";
            }
        } while (playerInput == 11);

    }

    
    void acessfolders()
    {
   
      cout << "Stored passwords:\n";
      for (int i = 0; i < folder.size(); i++)
      {
        cout << folder[i] << endl;
      }
 
      cout << "Enter the initial of the folder to access.\n";
      cin >> playerAnswer;
      do {
          switch (playerAnswer)
          {
          case 'E':
              cout << "You accessEmployee folder.\n";
              break;

          case 'B':
              cout << "You access Employee folder.\n";
              break;

          case 'L':
              cout << "You access Loan Applications folder.\n";
              break;

          case 'P':
              cout << "You access Password folder.\n";
              extractPasswards();
              break;

          }
      } while (playerAnswer == 'P');
    }

    void extractPasswards()
    {
        cout << "You get all the passwards.\n";
        seeAllpasswards();

    }

    void seeAllpasswards()
    {
        cout << "Stored passwords:\n";
        for (int i = 0; i < password.size(); i++) {
            cout << password[i] << endl;
        }
        cout << "Save the passward somewhere. It will help you later\n";
    }

    

};


class clientHDD : HDD
{
public:

    clientHDD() : HDD("CryptoHorizon", 200, { 1234, 5678, 91011, 1213, 1415 }, { " Employee", "Bank_Records", "Loan_Applications" ,"Passcodes" }, true)
    {
        cout << "<<HDD detals>>\n";
        cout << "Bank n*me:" << bankName << endl;
        cout << "HDD Memory:" << memorySpace << endl;
       
     }
};

class Client
{
private:
    string ClientName;
    TaskLevel taskLevel;
    char playerAnswer;
   

public:
    Client(string name) :ClientName(name){}

    void assignTaskCall()
    {
        
        cout << " Hello, I have a task for you,do you want to take the task\n";
        cout << " press Y for the accepting the offer N for declining it...\n";
        cin >> playerAnswer;
        if (playerAnswer == 'Y' || playerAnswer == 'y')
        {
            //logic
            explainTask();
        }
        else
        {
            // logic
            cout << " Thanks do not disclose the task, and do not disclose it...\n";
            cout << " call cut.......\n";
        }
    }

    void explainTask()
    {
        
        cout << "The task is.................\n ";
        cout << "Also sending you the HDD. For ur help..\n";
        
        cout << " call cut.......\n";
    }




};



// Base class for all hackers
class Hacker
{
protected:
    string name;
    SkillLevel skillLevel;
    TraceLevel traceLevel;

    vector<int> cryptos;
    char playerAnswer;
    
    vector<Inventory> inventories;
    bool hasLaptop;
    bool hasVPN;


    //object reference
    Client* client;
    HDD* clientHdd;



public:
    Hacker(string hackerName, SkillLevel hackerSkill, vector<Inventory> inventoryList, TraceLevel hackerTraceLevel)
        : name(hackerName), skillLevel(hackerSkill), inventories(inventoryList), traceLevel(hackerTraceLevel) 
    {
        client = nullptr;
        clientHdd = nullptr;

    }
   
    ~Hacker()
    {
        delete client;  // Free memory
    }
    // Converts inventory enum to string
    string inventoryToString(Inventory item)
    {
        switch (item)
        {
        case Inventory::laptop: return "Laptop";
        case Inventory::signalBlocker: return "Signal Blocker";
        case Inventory::hardDrive: return "hardDrive";
        case Inventory::negativeEye: return "Negative Eye";
        case Inventory::passwords: return "Passwords";
        case Inventory::VPN: return "VPN";
        default: return "Unknown Item";
        }
    }

    void receiveCall()
    {
        client = new Client("Hamster");
        
        cout << "You getting a call, Want to receive?? press R to receive the call...\n";
        cin >> playerAnswer;
        
        do {
            if (playerAnswer == 'r' || playerAnswer == 'R')
            {
                client->assignTaskCall();
            }
            else
            {
                cout << "Not able to receive the call.\n";
            }
        } while (playerAnswer == 'r' || playerAnswer == 'R');


        cout << " press R to receive the hardDrive.\n";
        cin >> playerAnswer;
        do {
            if (playerAnswer == 'i' || playerAnswer == 'I')
            {
                receiveHDD();
            }
            else
            {
                cout << "Not able to receive the HDD.\n";
            }
        } while (playerAnswer == 'i' || playerAnswer == 'I');
        
    }

    void receiveHDD() 
    {
        clientHdd = new HDD("CryptoHorizon", 200, { 1234, 5678, 91011, 1213, 1415 }, { "Employee", "Bank_Records", "Loan_Applications", "Passcodes" }, true);
        clientHdd->connectHDD();

    }
    

    // Display inventory
    void showInventory() 
    {
        do 
        {
            cout << "press I for showing all the inventory options \n";
            cin >> playerAnswer;
            if (playerAnswer == 'I' || playerAnswer == 'i')
            {
                cout << "Hacker name:" << name << " Inventory:\n";
                for (const auto& item : inventories)
                {
                    cout << "- " << inventoryToString(item) << endl;
                }
            }
            else
            {
                cout << "No Inventory found\n";
            }

        } while (playerAnswer == 'I' || playerAnswer == ' i');
        
    }

    virtual void hack()
    {
        if (!hasLaptop)
        {
            cout << " You can not able to hack it, you have atleast laptop with you for hacking.";
        }
        cout << "HACKING... device name -zxy...\n";
        cout << "10 sec more...\n";
    }

    void upgrade()
    {
        cout << "You are upgraded...\n";
    }

    void evade_trace()
    {
        cout << "You are being traced by cybersecurity!\n";
        cout << "Using Signal Blocker, VPN, and GPS Jammer to evade...\n";
    }

    // Getters
    string getHackerName() { return name; }
    SkillLevel getHackerSkill() { return skillLevel; }
    vector<Inventory> getInventories() { return inventories; }
    vector<int> getCryptoCount() { return cryptos; }
};


// Player-controlled hacker
class PlayerHacker : public Hacker
{

private:
    int playerInput;
  

public:
    PlayerHacker() : Hacker("Jimmy", SkillLevel::Beginner, { Inventory::laptop, Inventory::VPN, Inventory::hardDrive }, TraceLevel::medium)
    {
        cout << "I am a hacker, and you can call me Jimmy\n";
        hasLaptop = true;
        hasVPN = true;
        
    }

    void hack()
    {
        if (hasLaptop == true && hasVPN == true)
        {
            cout << "Whats a plan, How do you want to break in?";
            cout << " [1] Guess the admin password";
            cout << " [2] Send a fake email to trick an employee (phishing)";
        }

        do {
            cin >> playerInput;
            
            switch (playerInput)
            {
            case 1: 
                cout << "Guess the admin password logic...\n";
                cout << " 1) connect the cliend hdd.\n";
                cout << " 2) scan it and find the currect password\n";
                cout << " 3) be careful and type the right password. if wrong there will be chances of trace...\n";


                break;
            case 2:
                cout << "Fake email (phishing) logic...\n";
                break;
            default:
                cout << "Try a better approch to break in...";
                    break;
         
            }
        } while (playerInput != 0);

    }

    

};








int main()
{
    PlayerHacker player;
    player.receiveCall();

    player.showInventory();

    cout << " Thank you for playing cyber heist................................................\n";
    return 0;
}