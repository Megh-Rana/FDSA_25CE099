/*
 * Problem 1: Fixed-Capacity Token Counter Queue Implementation
 * 
 * SOLUTION EXPLANATION:
 * ====================
 * 
 * Front and Rear Tracking:
 * ------------------------
 * - REAR pointer points to the position where next element WILL be added
 * - FRONT pointer points to the position of first element waiting to be served
 * 
 * In a FIFO queue with fixed capacity:
 * - Queue size = rear - front + 1 (when using circular buffer)
 * - JOIN: increment rear, place element
 * - SERVE: save element at front, increment front
 * 
 * Key Point: FIXED-CAPACITY CIRCULAR QUEUE REUSES FREED SLOTS!
 * When we call serve(), we move front++, making that slot free.
 * The next join() operation can reuse freed slots or continue filling new ones.
 * 
 * Space Recycling Mechanism:
 * --------------------------
 * 1. Circular buffer wraps indices modulo capacity
 * 2. When served from front, those positions become logically empty
 * 3. Join operations wrap around and fill free slots
 * 4. Always check actual element count, not just position boundaries
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class TokenCounter {
private:
    vector<string> tokens;      // Storage array
    int capacity;               // Maximum number of tokens
    int front;                  // Index of first element to serve
    int rear;                   // Index where next element goes
    
public:
    TokenCounter(int cap) : capacity(cap), front(0), rear(-1) {
        tokens.resize(cap);
    }
    
    // Add a visitor token (join operation)
    bool join(const string& name) {
        int currentCount = calculateSize();
        
        if (currentCount >= capacity) {
            cout << "\nError: Token counter is FULL. Cannot add new token:" 
                 << " '" << name << "'" << endl;
            
            cout << "   - Current elements: " << currentCount << "/" << capacity << endl;
            cout << "   - No available slots (circular buffer checked for free space)" << endl;
            showQueueStatus();
            return false;
        }
        
        // In circular buffer, rear moves forward and wraps
        rear++;
        if (rear >= capacity) {
            rear = 0;  // Wrap around
        }
        
        tokens[rear] = name;
        cout << "\nSuccess: Token '" << name << "' added." << endl;
        cout << "   Position: index " << rear << endl;
        cout << "   Queue size now: " << calculateSize() << "/" << capacity << endl;
        
        showQueueStatus();
        return true;
    }
    
    // Serve a visitor (attend operation)
    bool serve() {
        int currentCount = calculateSize();
        
        if (currentCount <= 0) {
            cout << "\nError: Token counter is EMPTY. Cannot serve." << endl;
            showQueueStatus();
            return false;
        }
        
        // Save element at front and prepare to move past it
        int oldFrontPos = front % capacity;
        string served = tokens[oldFrontPos];
        
        // Mark as empty (slot becomes reusable)
        tokens[oldFrontPos] = "";
        
        cout << "\nSuccess: Served token '" << served << "'." << endl;
        cout << "   Old position (" << oldFrontPos << ") is now FREE/REUSABLE" << endl;
        
        // Move front pointer forward (slot recycling!)
        front++;
        
        int newSize = calculateSize();
        if (newSize <= 0) {
            // Queue empty - need to reset pointers
            front = 0;
        }
        
        cout << "   New front position: " << front % capacity << endl;
        cout << "   Queue size now: " << newSize << "/" << capacity << endl;
        
        showQueueStatus();
        return true;
    }
    
    // Get current size of queue (handles circular buffer)
    int calculateSize() const {
        if (rear < front) {
            // Circular wrap case
            return capacity - front + rear + 1;
        } else {
            return rear - front + 1;
        }
    }
    
    // Display queue status and details
    void showQueueStatus() const {
        int size = calculateSize();
        cout << "\n   Queue State Report:" << endl;
        cout << "   Size: " << size << "/" << capacity << endl;
        
        if (size <= 0) {
            cout << "   Contents: [EMPTY]" << endl;
            cout << "   Note: After serve(), slots at old front positions became FREE" << endl;
            cout << "   Front and rear pointers have converged - queue logically empty" << endl;
        } else {
            cout << "   Contents: [";
            
            // Print in circular order starting from front
            int startPos = front % capacity;
            bool first = true;
            
            for (int i = 0; i < size; i++) {
                int currentPos = startPos;
                
                // Handle wraparound: if we've gone full circle, stop
                if ((currentPos + 1) == startPos && i < size - 1) {
                    break;
                }
                
                if (!first) cout << ", ";
                if (capacity <= capacity && tokens.at(currentPos) != "") {
                    cout << tokens[currentPos];
                } else {
                    cout << tokens[currentPos] << " ";
                }
                first = false;
            }
            
            cout << "]" << endl;
        }
        
        cout << "   Pointer Positions (modulo capacity):" << endl;
        cout << "   - Front: index " << front << " -> " << (front % capacity) 
             << " (next element to serve)" << endl;
        cout << "   - Rear: index " << rear << " -> " << (rear + 1) % capacity 
             << " (logical back of queue)" << endl;
        
        cout << "\n   Explanation:" << endl;
        cout << "   - Front++ frees the slot where an element was served" << endl;
        cout << "   - Circular buffer allows join() to wrap and reuse freed slots" << endl;
    }
};

int main() {
    int n = 5;  // Maximum capacity
    
    cout << "========================================" << endl;
    cout << "   FIXED-CAPACITY TOKEN COUNTER SYSTEM  " << endl;
    cout << "========================================" << endl;
    cout << "Capacity: " << n << " tokens" << endl;
    
    TokenCounter counter(n);
    
    // Test: Add tokens
    cout << "\n\n--- OPERATION 1: Adding Tokens (A, B, C) ---" << endl;
    counter.join("A");
    counter.join("B");
    counter.join("C");
    
    cout << endl << "--- OPERATION 2: Adding more tokens (D, E) ---" << endl;
    counter.join("D");
    counter.join("E");
    
    cout << endl << "--- OPERATION 3: Try adding F when AT CAPACITY ---" << endl;
    counter.join("F");  // Should fail
    
    cout << "\n--- OPERATION 4: Serving tokens ---" << endl;
    counter.serve();   // Serves 'A', frees slot 0
    cout << "\n  After first serve:" << endl;
    counter.showQueueStatus();
    
    cout << "Serving again (serves 'B', frees another slot)..." << endl;
    counter.serve();
    cout << endl;
    
    cout << "\n--- OPERATION 5: Add G (space appears freed!) ---" << endl;
    counter.join("G");
    
    cout << "\n--- OPERATION 6: Add H and I ---" << endl;
    counter.join("H");
    counter.join("I");
    
    cout << "\n\n=== ANSWERING KEY QUESTIONS ===" << endl;
    cout << endl;
    
    cout << "Q1: How solution tracks front and rear:" << endl;
    cout << "   - FRONT: Index of first waiting element (never decreases)" << endl;
    cout << "   - REAR: Logic position at back of queue (increments, wraps around)" << endl;
    
    cout << "\nQ2: How pointers move over time:" << endl;
    cout << "   JOIN operation:" << endl;
    cout << "     rear = (rear + 1) % capacity" << endl;
    cout << "     Place new token at tokens[rear]" << endl;
    cout << "     Front stays unchanged (still points to first waiting)" << endl;
    
    cout << "\n   SERVE operation:" << endl;
    cout << "     Save element at old front position" << endl;
    cout << "     front = (front + 1) % capacity" << endl;
    cout << "     Old slot becomes FREE/REUSABLE for next join" << endl;
    
    cout << "\nQ3: Space recycling when slots freed:" << endl;
    cout << "   When serve() is called, front++ moves past served element" << endl;
    cout << "   That position is now empty (we set tokens[oldFront]=\"\")" << endl;
    cout << "   Next join() will either:" << endl;
    cout << "     a) Continue filling non-wrapped positions, OR" << endl;
    cout << "     b) Wrap around to reuse freed slots at front if needed" << endl;
    cout << "   The circular buffer MODULO arithmetic handles this automatically!" << endl;
    
    return 0;
}
