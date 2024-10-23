/*

Purpose: Approximating the Geometrical Shape of Molecules
          
Description: This program predicts the molecular geometry of molecules
             based on the VSEPR theory. It processes an input file containing
             molecular formulas in the form ABb, where A is a central atom and
             b represents the number of surrounding B atoms. Based on the
             number of bonding and non-bonding electron pairs, it determines
             the approximate geometry of the molecule.

Author: Arpit Dahiya

*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream InFile; //Input file buffer
    ofstream OutFile; //Output file buffer

    InFile.open("molecules.txt"); //Open the input file

    if (!InFile) // Opening unsuccessful
    {
        //Printing the error message
        cerr << "There was a problem opening the input file" << endl;
        return 1; //Terminating the program
    }


    OutFile.open("geometricalshapes.txt"); //Open the output file

    if (!OutFile) // Opening unsuccessful
    {
        //Printing error message
        cerr << "There was a problem opening the output file" << endl;
        return 1; //Terminating the program
    }

    //Declaring the variables
    int b, v = 0, n, e;
    string A, B, geo; 

    while (InFile >> A >> B >> b) //Executing the code as long as there is input in any given line
    {
        //Assigning the number of valance electrons based on the element
        if (A == "Be")
        {
            v = 3;
        }
        else if (A == "C" || A == "Si")
        {
            v = 4;
        }
        else if (A == "N" || A == "P" || A == "As")
        {
            v = 5;
        }
        else if (A == "O" || A == "S" || A == "Se")
        {
            v = 6;
        }
        else if (A == "F" || A == "Cl" || A == "Br" || A == "I")
        {
            v = 7;
        }
        else if (A == "Xe")
        {
            v = 8;
        }

        //Calculating the number of non-bonding electrons(e)
        e = v - b;

        //Calculating the number of non-bonding electron pairs(n)
        n = e / 2;

        
        //Aproximating the shape based on the number of bonding and non banding pairs
        if (b == 2 && n == 0)
        {
            geo = "linear";
        }
        else if (b == 2 && (n == 1 || n == 2))
        {
            geo = "bent";
        }
        else if (b == 2 && n == 3)
        {
            geo = "linear";
        }
        else if (b == 3 && n == 0)
        {
            geo = "trigonal planar";
        }
        else if (b == 3 && n == 1)
        {
            geo = "trigonal pyramidal";
        }
        else if (b == 3 && n == 2)
        {
            geo = "T-shaped";
        }
        else if (b == 4 && n == 0)
        {
            geo = "tetrahedral";
        }
        else if (b == 4 && n == 1)
        {
            geo = "seesaw";
        }
        else if (b == 4 && n == 2)
        {
            geo = "square planar";
        }
        else if (b == 5 && n == 0)
        {
            geo = "bipyramidal";
        }
        else if (b == 6 && n == 0)
        {
            geo = "octahedral";
        }
        else
        {
            geo = "unknown";
        }

        // Output Statement(s)
        OutFile << "The geometrical shape of one " << A << " atom surrounded by " << b << " " << B << " atoms is " << geo << endl;
    }

    InFile.close(); //Closing the input file
    OutFile.close(); //Closing the output file

    return 0; //Closing the program
}