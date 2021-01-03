        /* ----------------------------------------------------------- 
         * Master mind: Number guessing game.
        Class: CS 141, Summer 2019. Monday and Wednesday 1pm 
        Author: Bhavana Laxmi Radharapu
        Professor: Mark Hallenbeck
        TA: Hasti Sharifi
        Description of Program: Game mastermind is a guessing game of 3-digit numbers.
        ----------------------------------------------------------- */
        #include<iostream>
        #include<cstdlib>

        using namespace std;
        int digit_1; //Random number generated
        int digit_2;
        int digit_3;
        string userInput; // The digits entered by the user
        const int guesses = 10; // Number of guesses given to the user
        int i;
        int x; // To check for the number of guesses by user
        int digitsCorrect; // digits in the right place
        int digitsOutOfPlace; // correct digits but in wrong place



        //-----------------------------------------------------------------------------------------


        int first_digit() // Function to check the occurrence of first digit in the three digit in the user's Input  
        {

            if (digit_1 == (userInput.at(0)-'0')) // To check if the first digit in random number and user Input is the same 
            {
                digitsCorrect =  digitsCorrect +1;  // Adding score to let the user know that a digit is in the right place      
            }

            else if (digit_1 == (userInput.at(1)-'0') || digit_1 == (userInput.at(2)-'0')) //To check if the first digit in random number and is in user Input 
            {
                digitsOutOfPlace = digitsOutOfPlace + 1; // Adding score to let the user know that a digit is in the wrong place 
            }
        }

        int second_digit() // Function to check the occurrence of second digit in the three digit in the user's Input 
        {
            if (digit_2 == (userInput.at(1)-'0'))
            {
                digitsCorrect = digitsCorrect+1;        
            }

            else if (digit_2 == (userInput.at(0)-'0') || digit_1 == (userInput.at(2)-'0'))
            {
                digitsOutOfPlace = digitsOutOfPlace +1;
            }
        }

        int third_digit() // Function to check the occurrence of thrid digit in the three digit in the user's Input 
        {
            if (digit_3 == (userInput.at(2)-'0')) 
            {
                digitsCorrect = digitsCorrect+1;
            }

            else if (digit_3 == (userInput.at(0)-'0')||digit_3 == (userInput.at(1)-'0'))
            {
                digitsOutOfPlace = digitsOutOfPlace +1;
            }
        }

        //----------------------------------------------------------------------------------------

        int main(){


        cout << "Program: 2 MasterMind\n"
             <<"The program selects 3 distinct random digits 0..9.\n"
             <<"On each turn you guess 3 digits. The program indicates\n"
             <<"how many are correct. You have 10 moves to guess the number.\nGood luck!\n"
             <<"Input of 000 displays the hidden digits. Input of 999 exits the program\n"
             <<"                      In place   Out of place \n"
             <<"                      --------   ------------\n";

            do // loop to generate random number so that the number does not repeat
            {
                srand(time(0));
                digit_1 = (rand()%8)+1;
                digit_2 = (rand()%9);
                digit_3 = rand()%8;
            }
            while ((digit_1 == digit_2)||(digit_2==digit_3)||(digit_3==digit_1));

        //--------------------------------------------------------------------------------------    

            for (i = 1; i <= guesses ; i++)
            {
                cout<<i<<"."<<"Your guess:";
                cin >> userInput;
                digitsCorrect = 0;
                digitsOutOfPlace = 0;


                if (userInput == "000") // To check if the user wants to see the hidden Numbers
                {
                    cout<< "Hidden Numbers: "<<digit_1<<digit_2<<digit_3<<endl;
                }

                if (userInput == "999") // To check if the user wants to exit the program
                {
                    cout<<"Exiting Program..... "<<endl;
                        exit(0);
                }

                if ((digit_1 == (userInput.at(0)-'0')) || (digit_1 == (userInput.at(1)-'0')) || (digit_1 == userInput.at(2)-'0'))// To check for digit 1
                {
                    first_digit(); // Calling the function for the first digit
                }

                if ((digit_2 == (userInput.at(0)-'0')) || (digit_2 == (userInput.at(1)-'0')) || (digit_2 == userInput.at(2)-'0'))
                {
                    second_digit();
                }

                if ((digit_3 == (userInput.at(0)-'0')) || (digit_3 == (userInput.at(1)-'0')) || (digit_3 == userInput.at(2)-'0'))
                {
                    third_digit();
                }

                if ((digit_1 == (userInput.at(0)-'0')) && (digit_2 == (userInput.at(1)-'0')) && (digit_3 == userInput.at(2)-'0'))// To check if the user input matches the hidden numbers
                {
                    cout<<"**Congratulations!**"<<endl<<"Exiting Program..... "<<endl;
                    exit(0);
                }

                cout<<"    You entered:"<<userInput<<"       "<<digitsCorrect<<"            "<<digitsOutOfPlace<<endl;

            }

                    cout <<"\n\nBetter luck next time\n"<<endl<<"Exiting Program..... "<<endl;
                    exit(0); // To exit the program
        return 0;
        }

        //---------------------------------------------------------------------------------------------------






