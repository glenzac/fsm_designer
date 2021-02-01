#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <bitset>
#include "fort.hpp"

// Function to get string input from user
std::string getCurrentString()
{
    std::string s{};
    std::cout << "Enter the current state value:";
    std::cin >> s;
    return s;
}

//Function to calculate the bit length of state variable
int findBitLength(int x)
{
    int i{ 0 };
    while (x >= pow(2,i))
    {
        i = i + 1;
    }
    return i;
}

// Function to generate binary input values
std::vector<std::string> findInputStates(int x)
{
    std::vector<std::string> s{};
    for (int i = 0; i < pow(2,x); i++)
    {
        s[i] = std::bitset<2>(i).to_string();
        
        std::cout << s[i] << "\n";
    }
    return s;
}

int main()
{
    int stateCount{ };                              // to store the no. of states
    int inputCount{ };
    std::vector<std::string> currentStateVector;    // vector to store current states 
    std::vector<std::string> nextStateVector;       // vector to store next states
    std::cout << "States start from S0 to S";
    std::cin >> stateCount;
    int bit_length{ findBitLength(stateCount) };
    std::cout << bit_length;
    std::cout << "Enter the no. of inputs:";
    std::cin >> inputCount;
    std::vector<std::string> inputStates{ findInputStates(inputCount) };
    // resize vectors based on no. of states
    currentStateVector.resize(stateCount+1);      
    nextStateVector.resize(stateCount+1);
    
    
    std::cout << "Enter the initial state: ";
    std::cin >> currentStateVector[0];
    
    // Loop to get all the state transitions
    for (int i = 0; i < stateCount; i++)
    {
        for (int j = 0; j < inputCount; j++)
        {
            std::cout << "Enter the next state " << i + 1 << " :";
            std::cin >> nextStateVector[i];
            currentStateVector[i + 1] = nextStateVector[i];
        }

    }

    nextStateVector[stateCount] = currentStateVector[0];
/* 
    for (std::string i : currentStateVector)
        std::cout << i << ' ';
    std::cout << '\n';

    for (std::string i : nextStateVector)
        std::cout << i << ' ';
    std::cout << '\n';
*/



    std::cout << "-------------------------------- \n";
    // D Flip flop - exciatation table calculation
    std::vector<std::string> dffVector;
    dffVector.resize(stateCount + 1);
    dffVector = nextStateVector;
    std::cout << "D-flip flop: \n";

    for (std::string i : dffVector)
        std::cout << i << ' ';
    std::cout << '\n';
    std::cout << "--------------------------------  \n";

    //JK Flip flop - excitation table calculation
    std::vector<std::string> jkff_JVector;
    std::vector<std::string> jkff_KVector;
    jkff_JVector.resize(stateCount + 1);
    jkff_KVector.resize(stateCount + 1);
    jkff_JVector = nextStateVector;
    jkff_KVector = nextStateVector;
    for (int i = 0; i < stateCount+1; i++)
    {
        for (int j = 0; j < bit_length; j++)
        {
            if (currentStateVector[i][j] == '0' && nextStateVector[i][j] == '0')
            {
                jkff_JVector[i][j] = '0';
                jkff_KVector[i][j] = 'X';
            }
            else if (currentStateVector[i][j] == '0' && nextStateVector[i][j] == '1')
            {
                jkff_JVector[i][j] = '1';
                jkff_KVector[i][j] = 'X';
            }
            else if (currentStateVector[i][j] == '1' && nextStateVector[i][j] == '0')
            {
                jkff_JVector[i][j] = 'X';
                jkff_KVector[i][j] = '1';
            }
            else if (currentStateVector[i][j] == '1' && nextStateVector[i][j] == '1')
            {
                jkff_JVector[i][j] = 'X';
                jkff_KVector[i][j] = '0';
            }
        }
    }
    /*
    for (std::string i : jkff_JVector)
        std::cout << i << ' ';
    std::cout << '\n';

    for (std::string i : jkff_KVector)
        std::cout << i << ' ';
    std::cout << '\n';
    */

    //SR Flip flop - excitation table calculation
    std::vector<std::string> srff_SVector;
    std::vector<std::string> srff_RVector;
    srff_SVector.resize(stateCount + 1);
    srff_RVector.resize(stateCount + 1);
    srff_SVector = nextStateVector;
    srff_RVector = nextStateVector;
    for (int i = 0; i < stateCount + 1; i++)
    {
        for (int j = 0; j < bit_length; j++)
        {

            if (currentStateVector[i][j] == '0' && nextStateVector[i][j] == '0')
            {
                srff_SVector[i][j] = '0';
                srff_RVector[i][j] = 'X';
            }
            else if (currentStateVector[i][j] == '0' && nextStateVector[i][j] == '1')
            {
                srff_SVector[i][j] = '1';
                srff_RVector[i][j] = '0';
            }
            else if (currentStateVector[i][j] == '1' && nextStateVector[i][j] == '0')
            {
                srff_SVector[i][j] = '0';
                srff_RVector[i][j] = '1';
            }
            else if (currentStateVector[i][j] == '1' && nextStateVector[i][j] == '1')
            {
                srff_SVector[i][j] = 'X';
                srff_RVector[i][j] = '0';
            }
        }
    }

    //T Flip flop - excitation table calculation
    std::vector<std::string> tffVector;
    tffVector.resize(stateCount + 1);
    tffVector = nextStateVector;
    for (int i = 0; i < stateCount + 1; i++)
    {
        for (int j = 0; j < bit_length; j++)
        {

            if (currentStateVector[i][j] == '0' && nextStateVector[i][j] == '0')
            {
                tffVector[i][j] = '0';
            }
            else if (currentStateVector[i][j] == '0' && nextStateVector[i][j] == '1')
            {
                tffVector[i][j] = '1';
            }
            else if (currentStateVector[i][j] == '1' && nextStateVector[i][j] == '0')
            {
                tffVector[i][j] = '1';
            }
            else if (currentStateVector[i][j] == '1' && nextStateVector[i][j] == '1')
            {
                tffVector[i][j] = '0';
            }
        }
    }
    std::cout << "-----------------------------------------------------------------\n";
    std::cout << "|\tCS\t|\tNS\t|\tJ\t|\tK\t|\n";
    std::cout << "-----------------------------------------------------------------\n";
    for (int i = 0; i < stateCount + 1; i++)
    {
        std::cout << "|\t "<< currentStateVector[i] << '\t'<<"|";
        std::cout << "\t " << nextStateVector[i] << '\t' << "|";
        std::cout << "\t " << jkff_JVector[i] << '\t' << "|";
        std::cout << "\t " << jkff_KVector[i] << '\t' << "|";
        std::cout << '\n';
    }
    std::cout << "---------------------------------------------------------------- \n";

    fort::char_table table;
    table << fort::header;
    /* Fill each cell with operator[] */
    table[0][0] = "Current State";
    table[0][1] = "Next State";
    table[0][2] = "J";
    table[0][3] = "K";
    table << fort::endr;
    for (int i = 0; i < stateCount + 1; i++)
    {
        table[i + 1][0] = currentStateVector[i];
        table[i + 1][1] = nextStateVector[i];
        table[i + 1][2] = jkff_JVector[i];
        table[i + 1][3] = jkff_KVector[i];
    }


    /* Set center alignment for the 1st and 3rd columns */
    table.column(0).set_cell_text_align(fort::text_align::center);
    table.column(1).set_cell_text_align(fort::text_align::center);

    std::cout << table.to_string() << std::endl;
}


