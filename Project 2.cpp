#include<iostream>  
#include<fstream>  
#include<string>  
#include<cstdio>
using namespace std;
int main()
{
 
    int choice;
    while (true)
    {
        string id, name, age, disease, searchID;
        cout << "==============================" << endl;
        cout << " HOSPITAL MANAGEMENT SYSTEM " << endl;
        cout << "==============================\n" << endl;
        cout << "1.Add Record" << endl;
        cout << "2.View Record" << endl;
        cout << "3.Search Record" << endl;
        cout << "4.Edit Records" << endl;
        cout << "5.Delete Record" << endl;
        cout << "6.Exit:" << endl;
        cout << "Enter your choice:\t";
        cin >> choice;

        if (choice == 1)  //Add Records  
        {
            ofstream file("hospital.txt", ios::app);
            cout << "\nEnter Patient ID:";
            cin >> id;
            file << id << endl;
            cout << "Enter Patient Name:";
            cin >> name;
            file << name << endl;
            cout << "Enter Patient Age:";
            cin >> age;
            file << age << endl;
            cout << "Enter Disease:";
            cin >> disease;
            file << disease << endl;
            file.close();
            cout << "\t\tRecord added successfully" << endl;
        }

        else if (choice == 2) // View Records
        {
            ifstream file("hospital.txt");
            if (!file)
            {
                cout << "Error opening file!" << endl;
            }
            else
            {
                string line;
                cout << "\n\t\tAll Patient Records\n";

                while (getline(file, line))
                {
                    cout << line << endl;
                }

                file.close();
            }
        }

        else if (choice == 3) //TOSEARCH
        {
            ifstream file("hospital.txt");
            if (!file)
            {
                cout << "Error opening file" << endl;
            }
            else
            {
                string id, name, age, disease;
                string searchid;
                bool searched_record = false;
                cout << "Enter the ID you want to search" << endl;
                cin >> searchid;
                cin.ignore();
                while (getline(file, id))
                {
                    getline(file, name);
                    getline(file, age);
                    getline(file, disease);
                    if (id == searchid)
                    {
                        cout << "ID: " << id << endl;
                        cout << "Name: " << name << endl;
                        cout << "Age: " << age << endl;
                        cout << "Disease: " << disease << endl;
                        cout << "Record of the ID searched has been displayed" << endl;
                        searched_record = true;
                        break;
                    }
                }
                file.close();
            }
        }
        else if (choice == 4) // TO EDIT
        {
            string id, name, age, disease;
            string editid;
            bool edit_record = false;

            cout << "Enter the ID you want to edit: ";
            cin >> editid;
            cin.ignore();

            ifstream file("hospital.txt");
            ofstream newFile("newhospital.txt");

            while (getline(file, id))
            {
                getline(file, name);
                getline(file, age);
                getline(file, disease);

                if (editid == id)
                {
                    cout << "Enter new record of the patient:" << endl;
                    cout << "ID: ";
                    getline(cin, id);
                    cout << "Name: ";
                    getline(cin, name);
                    cout << "Age: ";
                    getline(cin, age);
                    cout << "Disease: ";
                    getline(cin, disease);
                    edit_record = true;
                }

                newFile << id << endl;
                newFile << name << endl;
                newFile << age << endl;
                newFile << disease << endl;
            }

            file.close();
            newFile.close();

            remove("hospital.txt");
            rename("newhospital.txt", "hospital.txt");

            if (edit_record)
                cout << "Record edited successfully." << endl;
            else
                cout << "No record found with that ID." << endl;
        }
        else if (choice == 5)// To Delete  
        {
            ofstream file("hospital.txt");
            file.close();
            cout << "All records deleted successfully" << endl;
        }


        else  if (choice == 6) //Exit  
        {
            cout << "Exiting program..." << endl;
            break;
        }

    }

    return 0;
}