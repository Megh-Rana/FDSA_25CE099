/*
 * Problem 2: Unlimited-Capacity Hospital Patient Queue
 * 
 * Description:
 * An emergency ward with no upper limit on waiting patients.
 * Patients arrive at the rear, are attended from the front (FIFO).
 * No full queue error - unlimited capacity.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class HospitalWardQueue {
private:
    vector<string> patients;     // Array to store patient IDs/names
    int front;                   // Index of front element
    int rear;                    // Index of rear element
    size_t size;                 // Current number of patients
    
public:
    // Constructor
    HospitalWardQueue() : front(0), rear(-1), size(0) {
        // No capacity limit - vector will grow as needed
    }
    
    // Function to add a patient (arrive operation)
    bool arrive(const string& id) {
        rear++;                                               // Increase rear pointer (add at back)
        patients.push_back(id);                               // Add patient at rear
        size++;                                                // Increment size
        cout << "Arrived: Patient " << id 
             << " at position [" << rear << "]" << endl;
        cout << "Current front patient: " << (size > 0 ? patients[front] : "Empty") << endl;
        
        // Display queue state
        if (size > 0) {
            cout << "--- Queue State ---" << endl;
            cout << "[Front:]";
            for (int i = front; i < size; i++) {
                printf("%s%s", patients[i].c_str(), (i == rear - 1) ? "" : ", ");
            }
            cout << "[Rear]" << endl;
            cout << "Front index: " << front << " -> Patient: " << patients[front] << endl;
            cout << "Rear index: " << rear << endl;
        }
        return true;
    }
    
    // Function to attend to a patient (attend operation)
    bool attend() {
        if (size == 0 || front > rear) {                     // Check if queue is empty
            cout << "Error: No patients in ward. Cannot attend." << endl;
            return false;
        }
        
        string attended = patients[front];                   // Get patient at front
        
        // Move front pointer forward (remove from front)
        patients.erase(patients.begin() + front);            // Remove element at front
        if (front > 0) {                                      // Restore array after erase
            for (int i = front; i < size - 1; i++) {
                patients[i] = patients[i + 1];
            }
        }
        
        rear--;                                               // Decrease rear pointer
        front++;                                              // Increment front pointer
        size--;                                                 // Decrement size
        
        cout << "Attended: Patient " << attended << endl;
        cout << "Current front patient: " << (size > 0 ? patients[front] : "Empty") << endl;
        
        // Display queue state
        if (size > 0) {
            cout << "--- Queue State ---" << endl;
            cout << "[Front:]";
            for (int i = front; i < size; i++) {
                printf("%s%s", patients[i].c_str(), (i == rear - 1) ? "" : ", ");
            }
            cout << "[Rear]" << endl;
            cout << "Front index: " << front << " -> Patient: " << patients[front] << endl;
            cout << "Rear index: " << rear << endl;
        } else {
            cout << "--- Queue is now empty ---" << endl;
            cout << "Front index: " << front << endl;
            cout << "Rear index: " << rear << endl;
        }
        return true;
    }
    
    // Function to display current queue state with detailed information
    void showDetails() {
        if (size == 0) {
            cout << "--- Queue State ---" << endl;
            cout << "Queue: [Empty]" << endl;
            cout << "Front index: " << front << " (points to next free slot)" << endl;
            cout << "Rear index: " << rear << " (next available slot for new arrivals)" << endl;
        } else {
            cout << "--- Queue State ---" << endl;
            cout << "Current patients size: " << size << endl;
            cout << "[Front:]";
            for (int i = front; i < size; i++) {
                printf("%s%s", patients[i].c_str(), (i == rear - 1) ? "" : ", ");
            }
            cout << "[Rear]" << endl;
            cout << "Front index: " << front << endl;
            cout << " -> Points to patient: " << patients[front] << endl;
            cout << "Rear index: " << rear << endl;
            cout << " -> Last patient: " << patients[rear] << endl;
            cout << "Queue is NOT empty, slots are reusable!" << endl;
        }
    }
    
    // Function to get front patient (without removing)
    string getCurrentFront() {
        if (size == 0) {
            return "Empty";
        }
        return patients[front];
    }
};

// Test the hospital ward queue system
int main() {
    cout << "===== Hospital Emergency Ward Queue =====" << endl;
    cout << "Unlimited capacity queue" << endl;
    cout << "Patients arrive at back, attended from front (FIFO)" << endl;
    cout << "==========================================" << endl << endl;
    
    HospitalWardQueue ward;
    
    // Scenario 1: Multiple patients arriving
    cout << "SCENARIO 1: Emergency rush" << endl;
    cout << "==========================================" << endl;
    ward.arrive("P001");     // First patient arrives
    ward.arrive("P002");
    ward.arrive("P003");
    
    cout << endl;
    
    // Scenario 2: Attending patients one by one
    // Show that front moves, slots free up, but rear stays where it is
    cout << endl << "SCENARIO 2: Attending patients" << endl;
    cout << "==========================================" << endl;
    ward.attend();           // Attend P001
    ward.attend();           // Attend P002
    
    printf("SCENARIO 3: Attending last patient (P003)\n");
    printf("=" + string(50, '=') + "\n") << endl;
    
    ward.attend();
    
    printf("%s\n", "SCENARIO 4: Queue is now empty");
    printf("=====================================\n" "\n");
    
    // Show details when queue is empty
    printf("When queue is empty:\n");
    printf("- Front = %d (points to next free slot for new arrivals)\n", ward.front);
    printf("- Rear = %d (next available slot, same as front when empty)\n", ward.rear);
    printf("- Both point to the same reused location\n\n");
    
    // Scenario 5: New patients after queue became empty
    cout << "SCENARIO 5: New patients arrive when 'queue' appeared empty" << endl;
    cout << "==========================================" << endl;
    ward.rear++;             // Manually show rear is reused from front position
    printf("Rear incremented to %d (reusing freed slot)\n\n", ward.rear);
    
    // Note: We need to re-implement with proper array management
    // For unlimited queue, we use dynamic allocation
    cout << "Note: In real implementation, 'attend()' uses erase() which" << endl;
    cout << "shifts elements and automatically updates front/rear pointers." << endl;
    cout << endl;
    
    // Let's show the actual behavior with better test
    HospitalWardQueue ward2;
    
    printf("Testing with actual dynamic queue:\n\n");
    printf("-- Arriving patients (P01, P02, P03): %s\n", "==================================");
    ward2.arrive("P01");
    ward2.arrive("P02");
    ward2.arrive("P03");
    
    printf("\n-- Attending patient by patient:\n\n");
    ward2.attend();           // Front moves right
    printf("After: Front -> %d, Rear -> %d, Size: %zu\n", ward2.front, ward2.rear, ward2.size);
    ward2.attend();
    printf("After: Front -> %d, Rear -> %d, Size: %zu\n", ward2.front, ward2.rear, ward2.size);
    ward2.attend();
    
    printf("\n-- Queue empty state:\n");
    printf("Front = %d (next free slot)\n", ward2.front);
    printf("Rear = %d (same as front when empty)\n\n", ward2.rear);
    
    // Now add more patients - front and rear continue moving
    printf("-- Adding new patients:\n");
    ward2.arrive("P04");
    ward2.arrive("P05");
    
    // This demonstrates recycling of freed slots!
    cout << endl << "==========================================" << endl;
    printf("Key Insights About Front/Rear Pointers:\n\n");
    printf("1. JOIN (arrive) operation:\n");
    printf("   - Rear++ then add patient at new rear position\n");
    printf("   - Front remains unchanged (still points to first waiting patient)\n");
    printf("   - Space is used from current rear position moving forward\n\n");
    
    printf("2. ATTEND (serve) operation:\n");
    printf("   - Patient at front is removed/processed\n");
    printf("   - Front++ moves the pointer to next patient (recycling freed slot)\n");
    printf("   - Rear position stays same (rear of actual queue moves left logically,\n");
    printf("     though in dynamic vector we use erase)\n\n");
    
    printf("3. Space recycling:\n");
    printf("   - When patients are attended, their slots become free\n");
    printf("   - Front pointer moves right, showing slot becomes reusable\n");
    printf("   - Empty spaces can be reused for new arrivals without shifting!\n");
    printf("   - No 'full' error can ever happen with unlimited capacity\n\n");
    
    printf("4. Handling apparent space shortage:\n");
    printf("   - If rear < max_capacity and slots between front/rear are free,\n");
    printf("     new arrivals can reuse them immediately (no full queue)\n");
    printf("   - Front pointer only moves forward and never decreases\n");
    printf("   - Each attend frees a slot for future use\n\n");
    
    return 0;
}
