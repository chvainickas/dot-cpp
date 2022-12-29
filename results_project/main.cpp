#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cmath>

using namespace std;
/// class declaration
class exams {
public:
string get_grades(float marks_p);
void report_1_heading();
void report_2_heading();
float get_CAO_points(string grade);

private:
float dm_mark;
string dm_grade;
string subjects[6] = {"OOP", "Web A", "PPD", "Database", "Math", "Soft A"};
float dm_CAO_points;
};

class validation{
public:
    bool valid_mark2(float mark);
    bool Valid_user();
private:
    string dm_Username, dm_password;
    float dm_mark2;
    int c=0;
};

/// Reports
void exams::report_1_heading(){
    cout << setw(50) <<"QQI Certificate Marks%" << endl;
    cout << setw(15) << "Names";
    for (int i = 0; i<6;i++)
    {
    cout << setw(10) << subjects[i];
    }
    cout << setw(10) << "Average";
    cout << endl;
}
///TODO report 2 heading
void exams::report_2_heading(){
    cout << setw(50) <<"QQI Grades & CAO points" << endl;
    cout << setw(15) << "Names";
    for (int i = 0; i<6;i++)
    {
    cout << setw(10) << subjects[i];
    }
    cout << setw(10) << "  CAO POINTS";
    cout << endl;
}

string exams::get_grades(float mark_p){
    dm_mark = mark_p;
    if (dm_mark >= 80)
    {dm_grade = "D";}
    if (dm_mark >= 65 && dm_mark <80)
    {dm_grade = "M";}
    if (dm_mark >= 50 && dm_mark < 65)
    {dm_grade = "P";}
    if (dm_mark < 50)
    {
        dm_grade = "F";
    }

return dm_grade;
}

string names[6] = {"H Higgins","R McIlroy","M Solan","K Harris","S Coffee","G Baker"};

float marks[6][6] = {
    50,50,50,50,50,50,
    60,80,75,50,60,75,
    80,55,65,59,55,70,
    60,68,75,50,60,55,
    60,70,70,67,70,70,
    90,90,90,90,90,90,
};

float exams::get_CAO_points(string grade)

{
    dm_grade = grade;
    if (dm_grade == "D" )
    {
        dm_CAO_points = 50;
    }
    if (dm_grade == "M" )
    {
        dm_CAO_points = 33;
    }
    if (dm_grade == "P" )
    {
        dm_CAO_points = 16;
    }
    if (dm_grade == "U" )
    {
        dm_CAO_points = 0;
    }

    return dm_CAO_points;

}

bool validation::valid_mark2(float mark)
{
    dm_mark2 = mark;
    if (dm_mark2 <0 || dm_mark2 >100)
    {
        cout << dm_mark2 << "is not a valid mark" << endl;
        return false;
    }
    else {
        return true;
    }
}
/// Login Function
bool validation::Valid_user() {
    start:c = c + 1;
    if (c > 2) {
        cout << "Goodbye" << endl;
        exit(0);
    }

    cout << "You have two attempts to log on" << endl;

    start2:
    cout <<"______________________________________"<< endl;
    cout <<"|         Login screen               |" << endl;
    cout << "|" << setw(37) << "|" << endl;
    cout << "|" << setw(37) << "|" << endl;
    cout << "|" << setw(37) << "|" << endl;

    cout << "|Key in username (User1) ? ";
    cin >> dm_Username;
    cout << "|" << setw(37) << "|" << endl;
    cout << "|" << setw(37) << "|" << endl;
    cout << "|" << setw(37) << "|" << endl;
    cout << "|Key in password (password) ? ";
    ///Code to mask password
    char c = ' ';
    dm_password = "";
    while ( c != 13 )
    {
        c = _getch();
        if ( c != 13 )
        {dm_password = dm_password +c ;
            cout << "*";
        }}
    ///cin >> dm_password;
    cout << "|" << setw(37) << "|" << endl;
    cout << "|" << setw(37) << "|" << endl;

    if (dm_Username == "User1" && dm_password == "password") {

        cout <<"|             Valid User             |" << endl;
        cout <<"|____________________________________|" << endl;
    }
    else{
        cout <<"|          Invalid user              |"<<endl;
        ///cout <<"|____________________________________|" << endl;
        goto start;
    }


}

int row_total;
int CAO_total;
string grade[6][6];
int column_totals[6];

int main() {
    system("COLOR 74");
    class validation user1;
    user1.Valid_user();

    class exams students[6];
    students[0].report_1_heading();
    for (int row = 0; row < 6; row++) {
        cout << setw(15) << names[row];
        for (int column = 0; column < 6; column++) {
            row_total = row_total + marks[row][column];
            column_totals[column] = column_totals[column] + marks[row][column];
            cout << setw(10) << marks[row][column];
        }
        cout  << setprecision(2) << setw(10)<< double (row_total/6) << endl;
        row_total = 0;

    }

    cout << setw(15U)<< "Average" ; // Print average mark for each subject
    for (int i=0 ; i<6 ; i++)
    {
        cout << fixed << setprecision(2) << setw(10)<< double(column_totals[i]/6)  ;
    }
    cout << endl;


    students[0].report_2_heading();
    for (int row = 0; row < 6; row++) {
        cout << setw(15) << names[row];
        CAO_total = 0;
        for (int column = 0; column < 6; column++) {
            cout << setw(10) << students[row].get_grades(marks[row][column]);
            grade[row][column] = students[row].get_grades(marks[row][column]);
            CAO_total = CAO_total + students[row].get_CAO_points(grade[row][column]);
        }
        cout << setw(10) << CAO_total;
        cout << endl;
    }

}