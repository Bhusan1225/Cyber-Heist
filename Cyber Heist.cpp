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

public:
    HDD(string name, int space, vector<int> passwords, vector<string> folders, bool checkconnection) : bankName(name), memorySpace(space), password(passwords), folder(folders), isConnected(checkconnection)
    {
        cout << " HDD is connecting..... wait\n";
    }

    void scanHDD()
    {
        cout << " Scanning the required files.\n";

    }

    void scanedfolders()
    {
        if (isConnected == true)
        {
            cout << "Stored passwords:\n";
            for (int i = 0; i < folder.size(); i++)
            {
                cout << folder[i] << endl;
            }

        }

    }

    void extractPasswards()
    {
        cout << " you can see all the passwards.\n";
        seeAllpasswards();

    }

    void seeAllpasswards()
    {
        cout << "Stored passwords:\n";
        for (int i = 0; i < password.size(); i++) {
            cout << password[i] << endl;
        }
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
    char playerInput;
    
    vector<Inventory> inventories;
    bool hasLaptop;
    bool hasVPN;

public:
    Hacker(string hackerName, SkillLevel hackerSkill, vector<Inventory> inventoryList, TraceLevel hackerTraceLevel)
        : name(hackerName), skillLevel(hackerSkill), inventories(inventoryList), traceLevel(hackerTraceLevel) {
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

    void Call()
    {
        cout << "You getting a call, Want to receive?? press c to receive the call...\n";
        cin >> playerInput;
        if (playerInput == 'c' || playerInput == 'C')
        {

        }
    }

    // Display inventory
    void showInventory() 
    {
        do 
        {
            cout << "press I for showing all the inventory options \n";
            cin >> playerInput;
            if (playerInput == 'I' || playerInput == 'i')
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

        } while (playerInput == 'I' || playerInput == ' i');
        
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
    HDD* hdd;

public:
    PlayerHacker() : Hacker("Jimmy", SkillLevel::Beginner, { Inventory::laptop, Inventory::VPN, Inventory::hardDrive }, TraceLevel::medium)
    {
        cout << "I am a hacker, and you can call me Jimmy\n";
        hasLaptop = true;
        hasVPN = true;
        hdd = nullptr;
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

    void connectHDD()
    {
        do {
            cout << "press 11 to connect the HDD.\n";
            cin >> playerInput;
            if (playerInput == 11)
            {
                //logic
            }
            else
            {
                cout << " wrong input try again.\n";
            }
        } while (playerInput == 11);
    }

};


class clientHDD : HDD
{
public:

    clientHDD() : HDD("CryptoHorizon", 200, { 1234, 5678, 91011, 1213, 1415 }, { " Employee", "Bank_Records", "Loan_Applications" ,"Passcodes" }, true) 
    {

        cout << "Bank n*me:" << bankName << endl;
        cout << "HDD Memory:" << memorySpace << endl;
        if (isConnected == true)
        {
            cout << "The client's HDD is connected to your d*vice n*w.\n";
        }
        else 
        {
            cout << "Not connected now, try again...\n";
        }

    }
};






int main()
{
    PlayerHacker player;
    player.showInventory();
    return 0;
}