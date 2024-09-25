#include <iostream>
#include <string>
using namespace std;

struct Team
{
    int ID;
    string Name;
    string President;
    Team *next;

    Team(int id, string name, string president)
    {
        ID = id;
        Name = name;
        President = president;
        next = NULL;
    }
};

struct Player
{
    int ID;
    string Name;
    int TeamID;
    string Position;
    short Age;
    double Salary;
    Player *next;

    Player(int id, string name, int teamId,
        string position, short age, double salary)

    {
        ID = id;
        Name = name;
        TeamID = teamId;
        Position = position;
        Age = age;
        Salary = salary;
        next = NULL;
    }
};

class EgyptionLeagueSystem
{
private:
    Team *teamHead;
    Player *playerHead;

public:
    EgyptionLeagueSystem()
    {
        teamHead = NULL;
        playerHead = NULL;
    }

    // team operations
    void AddNewTeam(int id, string name, string president)
    {
        Team *newTeam = new Team(id, name, president);

        if (teamHead == NULL)
        {
            teamHead = newTeam;
            cout << "\n\nTeam Added Successfully.";
            return;
        }

        Team *Last = teamHead;
        while (Last->next != NULL)
        {
            Last = Last->next;
        }
        Last->next = newTeam;
        newTeam->next = NULL;

        cout << "\n\nTeam Added Successfully.";
    }

    void DisplayTeams()
    {
        if (teamHead == NULL)
        {
            cout << "\n\nNo teams in the system.";
            return;
        }

        Team *current = teamHead;
        cout << "Teams List: \n";
        while (current != NULL)
        {
            cout << "________________________\n\n";
            cout << "Name     : " << current->Name << endl;
            cout << "ID       : " << current->ID << endl;
            cout << "President: " << current->President << endl;
            cout << "________________________\n";
            current = current->next;
        }
    }

    Team *SearchTeamById(int teamID)
    {
        if (teamHead == NULL)
            return NULL;

        Team *search = teamHead;
        while (search != NULL)
        {
            if (search->ID == teamID)
                return search;

            search = search->next;
        }
        return NULL;
    }

    void RemoveTeamByID(int teamID)
    {
        Team *prev = teamHead, *current = teamHead;
        if (teamHead == NULL)
        {
            cout << "\nTeams List is Empty :-(\n\n";
            return;
        }

        if (current->ID == teamID)
        {
            // delete from first.
            teamHead = current->next;
            delete (current->next);
            return;
        }

        while (current != NULL && current->ID != teamID)
        {
            prev = current;
            current = current->next;
        }

        if (current == NULL)
            return;

        prev->next = current->next;
        current->next = NULL; // i can delete this line and the program will work.
        // because current node is isolated now in memor.
        delete (current);

        cout << "\n\nTeam Deleted Successfully.";
    }

    void UpdateTeamInfo(int teamID, string name, string president)
    {
        Team *update = SearchTeamById(teamID);

        if (update != NULL)
        {
            update->Name = name;
            update->President = president;
            cout << "\n\nTeam Updated Successfully.";
        }
        else
            cout << "\n\nTeam is not found.";
    }

    // player operations

    void AddNewPlayer(int id, string name, int teamId, string position, short age, double salary)
    {
        Player* newPlayer = new Player(id, name, teamId, position, age, salary);

        if (playerHead == NULL || salary > playerHead->Salary) {
            newPlayer->next = playerHead;
            playerHead = newPlayer;  //insert at begginning
            cout << "\nPlayer added successfully.\n";
        }

        else {
            Player* current = playerHead;
            Player* previous = NULL;

            while (current != NULL && salary <= current->Salary) {
                previous = current;
                current = current->next;
            }

            previous->next = newPlayer;
            newPlayer->next = current;
        }

        cout << "\nPlayer added successfully.\n";
    }

    void DisplayPlayersOfTeam(int teamID)
    {
        if (playerHead == NULL)
        {
            cout << "\n\nNo players in the team.";
            return;
        }

        Player* current = playerHead;
        cout << "Players List: \n";
        while (current != NULL)
        {
            if (current->TeamID == teamID)
            {
                cout << "________________________\n\n";
                cout << "Name     : " << current->Name << endl;
                cout << "ID       : " << current->ID << endl;
                cout << "Team ID  : " << current->TeamID << endl;
                cout << "Position : " << current->Position << endl;
                cout << "Age      : " << current->Age << endl;
                cout << "Salary   : " << current->Salary << endl;
                cout << "________________________\n";
                current = current->next;
            }
        }
    }

    Player* SearchPlayer(string PlayerName)
    {
        Player* search = playerHead;

        while (search != NULL)
        {
            if (search->Name == PlayerName)
                return search;
        }

        return NULL;
    }

    Player* SearchPlayer(int PlayerId)
    {
        Player* search = playerHead;

        while (search != NULL)
        {
            if (search->ID == PlayerId)
                return search;
        }

        return NULL;
    }

    void UpdatePlayer(int id, string name, int teamId, 
        string position, short age, int salary) //Method Overloading
    {
        Player* player = SearchPlayer(id);

        if (player != NULL)
        {
            player->Name = name;
            player->TeamID = teamId;
            player->Position = position;
            player->Age = age;
            player->Salary = salary;

            cout << "\nPlayer information updated successfully.\n";
        }
    }
};

enum enMainMenuOptions { 
    eTeamsList = 1, eAddTeam = 2, eDeleteTeam = 3, 
    eUpdateTeam = 4, eFindTeam = 5, ePlayerList = 6, 
    eAddPlayer = 7, eDeletePlayer = 8, eUpdatePlayer = 9, 
    eFindplayer = 10, eExit = 11
};

void _GoBackToMainMenue()
	{
		cout <<"\n\tPress any key to go back to Main Menue...\n";
		system("pause>0");
	}

void ShowMainMenu()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tMain Menue\n";
    cout << "===========================================\n";
    cout << "\t[1] Show Teams List.\n";
    cout << "\t[2] Add New Team.\n";
    cout << "\t[3] Delete Team.\n";
    cout << "\t[4] Update Team Info.\n";
    cout << "\t[5] Find Team.\n";
    cout << "\t[6] Show Players List.\n";
    cout << "\t[7] Add New Player.\n";
    cout << "\t[8] Delete Player.\n";
    cout << "\t[9] Update Player.\n";
    cout << "\t[10] Find Player.\n";
    cout << "\t[11] Exit.\n";
    cout << "===========================================\n";

}

int main()
{
    //ShowMainMenu();


    EgyptionLeagueSystem EgyptionLeague;

    do
    {
        ShowMainMenu();

        short choice = 0;
        cout << "Please choose what do you want to do [1 to 11]? ";
        cin >> choice;

        if (choice == 11)
        {
            system("cls");
            cout << "____________________\n";
            cout << "\n  End Of Program";
            cout << "\n____________________\n";
            break;
        }
        

        while (choice < 1 || choice > 11)
        {
            cout << "Please choose a number between [1 to 11]? ";
            cin >> choice;
        }

        enMainMenuOptions MainMenuOption = (enMainMenuOptions) choice;

        switch (MainMenuOption)
        {
        case enMainMenuOptions::eTeamsList:
        {
            system("cls");
            EgyptionLeague.DisplayTeams();
            _GoBackToMainMenue();
            break;
        }

        case enMainMenuOptions::eAddTeam:
        {
            system("cls");
            int id;
            string name;
            string president;

            cout << "Enter Team Id: ";
            cin >> id;

            cout << "Enter Team Name: ";
            getline(cin >> ws, name);

            cout << "Enter Team President: ";
            getline(cin, president);

            EgyptionLeague.AddNewTeam(id, name, president);
            _GoBackToMainMenue();
            break;
        }

        case enMainMenuOptions::eDeleteTeam:
        {
            system("cls");
            int id;
            cout << "Enter Team Id: ";
            cin >> id;

            EgyptionLeague.RemoveTeamByID(id);
            _GoBackToMainMenue();
            break;
        }

        case enMainMenuOptions::eFindTeam:
        {
            system("cls");
            int id;
            cout << "Enter Team Id: ";
            cin >> id;

            EgyptionLeague.SearchTeamById(id);
            _GoBackToMainMenue();
            break;
        }

        case enMainMenuOptions::eUpdateTeam:
        {
            system("cls");
            int id;
            cout << "Enter Team Id: ";
            cin >> id;

            string name;
            string president;

            cout << "Enter Team Name: ";
            getline(cin >> ws, name);
            cout << "Enter Team President: ";
            getline(cin, president);

            EgyptionLeague.UpdateTeamInfo(id, name, president);
            _GoBackToMainMenue();
            break;
        }

        case enMainMenuOptions::ePlayerList:
        {
            system("cls");
            int id;
            cout << "Enter Team Id: ";
            cin >> id;
            EgyptionLeague.DisplayPlayersOfTeam(id);

            _GoBackToMainMenue();
            break;
        }

        case enMainMenuOptions::eAddPlayer:
        {
            system("cls");
            int id;
            string name;
            int teamId;
            string position;
            short age;
            double salary;

            cout << "Enter Player Id: ";
            cin >> id;
            cout << "Enter Player Name: ";
            getline(cin >> ws, name);
            cout << "Enter Player position: ";
            getline(cin, position);
            cout << "Enter Team Id: ";
            cin >> teamId;
            cout << "Enter Player Age: ";
            cin >> age;
            cout << "Enter Player Salary: ";
            cin >> salary;

            EgyptionLeague.AddNewPlayer(id, name, teamId, position, age, salary);
            _GoBackToMainMenue();
            break;
        }

        case enMainMenuOptions::eDeletePlayer:
        {
            system("cls");
            int id;
            cout << "Enter Player Id: ";
            cin >> id;

            EgyptionLeague.DisplayPlayersOfTeam(id);
            _GoBackToMainMenue();
            break;
        }

        case enMainMenuOptions::eUpdatePlayer:
        {
            system("cls");
            int id;
            string name;
            int teamId;
            string position;
            short age;
            double salary;

            cout << "Enter Player Id: ";
            cin >> id;
            cout << "Enter Player Name: ";
            getline(cin, name);
            cout << "Enter Player position: ";
            getline(cin, position);
            cout << "Enter Team Id: ";
            cin >> teamId;
            cout << "Enter Player Age: ";
            cin >> age;
            cout << "Enter Player Salary: ";
            cin >> salary;

            EgyptionLeague.UpdatePlayer(id, name, teamId, position, age, salary);
            _GoBackToMainMenue();
            break;
        }

        case enMainMenuOptions::eFindplayer:
        {
            system("cls");
            int id;
            cout << "Enter Player Id: ";
            cin >> id;

            EgyptionLeague.SearchPlayer(id);
            _GoBackToMainMenue();
            break;
        }
        }

    } while (true);

    return 0;
}
