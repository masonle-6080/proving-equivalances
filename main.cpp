#include <iostream> 
#include <vector>
#include <unordered_map>

class Node {
public:
    int validTail = -1;
    int validHead = -1;
};

void getInput(int &testCases, std::vector<std::unordered_map<int, Node*>> &testCaseNodes) {
    
    // going through every test case
    for(int i = 0; i < testCases; i++) {

        //creating a new list to hold the Nodes for each test case
        testCaseNodes.push_back({});
        int statements, implications;
        std::cin >> statements >> implications;

        int uniqueConnections = 0;

        // reading the implications
        for(int j = 0; j < implications; j++){
            int a, b;
            std::cin >> a >> b;

            int bothValid = 0;
            // if the node exists, check if a already has a tail and if b already has a head if both no, then a new unique connection
            // if one doesnt exists create a node for it and increase bothValid
            

            //fails only if already has head or tail
            if (testCaseNodes[i].find(a) != testCaseNodes[i].end() && testCaseNodes[i].find(b) != testCaseNodes[i].end() && testCaseNodes[i][a]->validTail == b){
                continue;
            }

            if (testCaseNodes[i].find(a) != testCaseNodes[i].end()){

                if(testCaseNodes[i][a]->validTail == -1) {
                    bothValid++;
                }
            } else {
                Node* newNode = new Node;
                newNode->validTail = b;
                newNode->validHead = -1;

                testCaseNodes[i][a] = newNode;
                bothValid++;
            }
            if (testCaseNodes[i].find(b) != testCaseNodes[i].end()){
                if(testCaseNodes[i][b]->validHead == -1) {
                    bothValid++;
                }
            } else {
                Node* newNode = new Node;
                newNode->validHead = a;
                newNode->validTail = -1;

                testCaseNodes[i][b] = newNode;
                bothValid++;
            }
            //std::cout << "testing " << a << " & " << b << "\n";

            if (bothValid == 2){
                uniqueConnections++;
                testCaseNodes[i][a]->validTail = b;
                testCaseNodes[i][b]->validHead = a;


                //std::cout << "valid connection \n";
                
            }
            
            //std::cout << a << "->validHead: " << testCaseNodes[i][a]->validHead << a << " ->validTail " << testCaseNodes[i][a]->validTail << "\n";
            //std::cout << b <<"->validHead: " << testCaseNodes[i][b]->validHead << b << " ->validTail " << testCaseNodes[i][b]->validTail << "\n";



        }
        std::cout  << statements - uniqueConnections << "\n";
       // std::cout << " | unique connections: " << uniqueConnections << "\n";
    }
}

int main(){
    int testCases;
    std::cin >> testCases;

    std::vector<std::unordered_map<int,Node*>> testCaseNodes;

    getInput(testCases, testCaseNodes);


    return 0;
}