#include <iostream>
#include <thread> 
#include <chrono> 
using namespace std;

class Blend {
public:
    void blendJuice() { 
        for (int step = 0; step < 5; step++) { 
            cout << "Blending..." << endl; 
            std::this_thread::sleep_for(chrono::seconds(1)); // Fixed: Added std::
        } 
    }
};

class Grind {
public:
    void grindJuice() { 
        cout << "Grinding..." << endl; 
        std::this_thread::sleep_for(chrono::seconds(5)); // Fixed: Added std::
    }
};

class JuiceMaker {
    Blend blendingTool;
    Grind grindingTool;
public:
    void makeJuice() { 
        blendingTool.blendJuice(); 
        grindingTool.grindJuice(); 
        cout << "Juice is ready!" << endl; 
    }
};

int main() {
    JuiceMaker juiceMachine;
    juiceMachine.makeJuice();
    return 0;
}