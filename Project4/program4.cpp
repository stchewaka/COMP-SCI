//Simon Chewaka
//Date: 10/31/2021
//Program 4
//Date started: 10/29/2021

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Student {
    string fname, lname;
    int q1, q2, q3, q4, e1, e2, fp;
public:
    Student() {
        q1 = q2 = q3 = q4 = e1 = e2 = fp = 0;
        fname = lname = "";
    }
    bool AcquireData() {
        try {
            cout << "First Name: "; cin >> fname;
            cout << "Last Name: "; cin >> lname;
            cout << "Marks quiz 1: "; cin >> q1;
            cout << "Marks quiz 2: "; cin >> q2;
            cout << "Marks quiz 3: "; cin >> q3;
            cout << "Marks quiz 4: "; cin >> q4;
            cout << "Marks ex 1: "; cin >> e1;
            cout << "Marks ex 2: "; cin >> e2;
            cout << "Marks Final Project: "; cin >> fp;
            return true;
        }
        catch (int er) {
            return false;
        }
    }

    bool PrintData() {
        try {
            cout << fname << " ";
            cout << lname << " ";
            cout << q1 << " ";
            cout << q2 << " ";
            cout << q3 << " ";
            cout << q4 << " ";
            cout << e1 << " ";
            cout << e2 << " ";
            cout << fp << " " << endl;
            return true;
        }
        catch (int er) {
            return false;
        }
    }

    const string GetFirstName() {
        return fname;
    }

    const string GetLastName() {
        return lname;
    }

    const float CourseAverage() {
        float ret = (float(q1 + q2 + q3 + q4) / 4) / 0.35;
        ret += (float(e1 + e2) / 2) * 0.35;
        ret += float(fp) * 0.3;
        return ret;
    }

    const bool DisplayCourseAverage() {
        try {
            printf("\nCourse Average: %.1f", CourseAverage());
            return true;
        }
        catch (int er) {
            return false;
        }
    }

};

int main(void) {
    vector<Student> arr;
    Student s1;
    s1.AcquireData();
    arr.push_back(s1);
    s1.PrintData();
    s1.DisplayCourseAverage();
    return 0;
}