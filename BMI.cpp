#include <bits/stdc++.h>
using namespace std;

struct Member
{
    int ID;
    double height, weight;
};

int main()
{
    int option;
    vector<Member> member;
    do
    {
        cout << "\n-----------Main Menu----------" << endl;
        cout << "\n1. Add Member" << endl;
        cout << "2. Update Member" << endl;
        cout << "3. Remove Member" << endl;
        cout << "4. Max Height & Weight" << endl;
        cout << "5. Min Height and Weight" << endl;
        cout << "6. Average Height and Weight" << endl;
        cout << "7. BMI Classification" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter Your option(1-8): ";
        cin >> option;

        if (option == 8)
        {
            cout << "\nBye!\n\n";
        }
        else if (option == 7)
        {
            int ID;
            cout << "\nEnter Member ID: ";
            cin >> ID;
            for (int i = 0; i < member.size(); i++)
            {
                if (member.at(i).ID == ID)
                {
                    double BMI = member.at(i).weight / (member.at(i).height * member.at(i).height);
                    cout << "BMI = " << BMI << fixed << endl;
                    if (BMI < 16)
                        cout << "Classification: Severe Thinness\n";
                    else if (BMI < 17)
                        cout << "Classification: Moderate Thinness\n";
                    else if (BMI < 18.5)
                        cout << "Classification: Mild Thinness\n";
                    else if (BMI < 25)
                        cout << "Classification: Normal\n";
                    else if (BMI < 30)
                        cout << "Classification: Overweight\n";
                    else if (BMI < 35)
                        cout << "Classification: Obese Class I\n";
                    else if (BMI < 40)
                        cout << "Classification: Obese Class II\n";
                    else if (BMI > 40)
                        cout << "Classification: Obese Class III\n";
                }
                else
                {
                    cout << "Cannot find!\n Please Try Again!" << endl;
                }
                system("pause");
            }
        }
        else if (option == 4)
        {
            double maxHeight = 0, maxWeight = 0;
            for (int i = 0; i < member.size(); i++)
            {
                if (member.at(i).height > maxHeight)
                {
                    maxHeight = member.at(i).height;
                }
                if (member.at(i).weight > maxWeight)
                {
                    maxWeight = member.at(i).weight;
                }
            }
            cout << "Max Height = " << maxHeight << "m" << endl;
            cout << "Max Weight = " << maxWeight << "kg\n"
                 << endl;
            system("pause");
        }
        else if (option == 5)
        {
            double minHeight = 10, minWeight = 400;
            for (int i = 0; i < member.size(); i++)
            {
                if (member.at(i).height < minHeight)
                {
                    minHeight = member.at(i).height;
                }
                if (member.at(i).weight < minWeight)
                {
                    minWeight = member.at(i).weight;
                }
            }
            cout << "Min Height = " << minHeight << "m" << endl;
            cout << "Min Weight = " << minWeight << "kg\n"
                 << endl;
            system("pause");
        }
        else if (option == 6)
        {
            double totalHeight = 0, totalWeight = 0;
            for (int i = 0; i < member.size(); i++)
            {
                totalHeight += member.at(i).height;
                totalWeight += member.at(i).weight;
            }
            cout << totalHeight / member.size() << endl;
            cout << totalWeight / member.size() << endl;
            system("pause");
        }
        else if (option == 2)
        {
            int ID, check = 0;
            cout << "\nEnter Member ID: ";
            cin >> ID;
            for (int i = 0; i < member.size(); i++)
            {
                if (member.at(i).ID == ID)
                {
                    cout << "Member ID found!!!\n";
                    cout << "Enter Height (m): ";
                    cin >> member.at(i).height;
                    cout << "Enter Weight (kg): ";
                    cin >> member.at(i).weight;
                    check = 1;
                    break;
                }
                if (check == 0)
                    cout << "Member ID not found!!!\n"
                         << endl;
            }
            system("pause");
        }
        else if (option == 3)
        {
            int id, check = 0;
            vector<Member> *a = &member;
            cout << "\nEnter Member ID to be deleted: ";
            cin >> id;

            for (auto it = a->begin(); it != a->end(); it++)
            {
                if (it->ID == id)
                {
                    a->erase(it);
                    check = 1;
                    cout << "Member ID Deleted!!!\n"
                     << endl;
                    break;
                }
            }
            if (check == 0)
                cout << "Member ID not found!!!\n"
                     << endl;

            /*for (int i = 0; i < member.size(); i++)
            {
                if (member.at(i).ID == ID)
                {
                    member.pop_back().at(i);

                    cout << "Member ID found!!!\n";
                    cout << "Enter Height (m): ";
                    cin >> member.at(i).height;
                    cout << "Enter Weight (kg): ";
                    cin >> member.at(i).weight;
                    check = 1;
                    break;
                }
                if (check == 0)
                    cout << "Member ID not found!!!\n"
                         << endl;
            }*/

            system("pause");
        }
        else if (option == 1)
        {
            struct Member a;
            cout << "\nEnter Member ID: ";
            cin >> a.ID;
            cout << "Enter Height (m): ";
            cin >> a.height;
            cout << "Enter Weight (kg): ";
            cin >> a.weight;
            member.push_back(a);
            system("pause");
        }
    } while (option != 8);
}