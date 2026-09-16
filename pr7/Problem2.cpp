/* Problem 2: Unlimited Capacity Hospital Patient Queue */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HospitalQueue {
    int front, rear;
    vector<string> patients;
    int patientCount;

public:
    HospitalQueue() : front(0), rear(-1), patientCount(0) {}

    bool arrive(const string& id) {
        patients[++rear] = id;
        patientCount++;
        cout << "Arrived: " << id << ", Current front: " << (patientCount > 0 ? patients[front] : "Empty") << endl;
        return true;
    }

    bool attend() {
        if (front > rear) {
            cout << "Error: No patients. Cannot attend." << endl;
            return false;
        }
        string patient = patients[front++];
        cout << "Attended: " << patient << ", Current front: " << (front <= rear ? patients[front] : "Empty") << endl;
        patientCount--;
        if (patientCount < 0) {
            front = 0;
            rear = patientCount++;
        }
        return true;
    }
};

int main() {
    cout << "Hospital Ward Queue (Unlimited Capacity)" << endl;
    cout << "=========================================" << endl;

    HospitalQueue ward;

    ward.arrive("P001");
    ward.arrive("P002");
    ward.arrive("P003");
    ward.arrive("P004");

    cout << "\nAttending patients:" << endl;
    ward.attend();
    ward.attend();
    ward.attend();

    cout << endl;
    cout << "Current front: " << ward.front << endl;
    cout << ward.front <= ward.rear ? ward.patients[ward.front] : "Empty" << endl;

    return 0;
}
