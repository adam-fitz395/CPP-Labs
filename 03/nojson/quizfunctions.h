#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

class Question 
{
	public:
		string questionText;
		vector<string> options;
		int correctOption;

	
};

class HighScorer
{
	public:
		string scorerName;
		int score;
};

vector<Question> initializeQuestion(string filename) 
{
    ifstream file(filename);
    int numQuestions;
    vector<Question> quizData;

    if (file.is_open())
    {
        file >> numQuestions;
        file.ignore();

        for (int i = 0; i < numQuestions; ++i)
        {
            Question thisQuestion;
            getline(file, thisQuestion.questionText);

            for (int questionIndex = 0; questionIndex <= numQuestions; questionIndex++)
            {
                string option;
                getline(file, option);
                thisQuestion.options.push_back(option);
            }

            file >> thisQuestion.correctOption;
            file.ignore();

            quizData.push_back(thisQuestion);
        }

        file.close();
    }
    
    else
    {
        cout << "Unable to open file: " << filename << endl;
    }

    return quizData;
}

vector<HighScorer> initializeHighscoreBoard(string filename)
{
    ifstream file(filename);
    vector<HighScorer> scoresData;
    string thisLine;
    int thisScore;

    if (file.is_open())
    {
        HighScorer thisScorer;

        while (file >> thisScorer.scorerName >> thisScorer.score)
        {
            scoresData.push_back(thisScorer);

        }
        
        file.close();
    }

    else
    {
        cout << "Unable to open file: " << filename << endl;
    }

    return scoresData;
}


void displayQuestion(Question questionToDisplay) 
{
	int size = questionToDisplay.options.size();

	cout << questionToDisplay.questionText << endl;
	
    for (int numQuestions = 0; numQuestions < size; numQuestions++)
	{
		cout << numQuestions + 1 << ". " << questionToDisplay.options[numQuestions] << endl;
	}
}

void displayScores(vector<HighScorer> highScores)
{
    cout << "HIGHSCORES" << endl;

        for (int scores = 0; scores < highScores.size(); scores++)
        {
            cout << "----------" << endl;
            cout << highScores.at(scores).scorerName << " - " << highScores.at(scores).score << endl;
        }
    
    cout << endl;
}

vector<HighScorer> appendScores(vector<HighScorer> highScores, string userName, int userScore)
{
    HighScorer newScorer;
    newScorer.scorerName = userName;
    newScorer.score = userScore;

    for (int scores = 0; scores < highScores.size(); scores++)
    {
        if (userScore >= highScores.at(scores).score)
        {
            highScores.insert(highScores.begin() + scores, newScorer);
            break;
        }
    }

    return highScores;
}

void writeScoresToFile(vector<HighScorer> highScores, string filename)
{
    ofstream file(filename);

    if (file.is_open())
    {
        for (int scores; scores < highScores.size(); scores++)
        {
            file << highScores.at(scores).scorerName << "\n";
            file << highScores.at(scores).score << "\n";
        }
    }
    
    else
    {
        cout << "Unable to open file: " << filename << endl;
    }
}

void makeQuiz()
{
    string userAnswer;
    vector<int> askedQuestions;
    int userScore = 0;
    string userName;
	char repeatChoice;
    vector<HighScorer> highScores = initializeHighscoreBoard("highscore.txt");

    cout << "Pleaser enter your name: ";
    cin >> userName;
    cout << endl;

    do
    {
        vector<Question> possibleQuestions = initializeQuestion("quiz.txt");
        srand(time(0));

        while (!possibleQuestions.empty() && askedQuestions.size() < possibleQuestions.size())
        {
            int randomQ;
            
            do
            {
                if (possibleQuestions.size() == 1)
                {
                    randomQ = 0;
                }

                else
                {
                    randomQ = rand() % possibleQuestions.size();
                }

            } while (find(askedQuestions.begin(), askedQuestions.end(), randomQ) != askedQuestions.end());

            askedQuestions.push_back(randomQ);
            Question qToDisplay = possibleQuestions[randomQ];

            displayQuestion(qToDisplay);
            cout << "Pick the correct number: ";
            cin >> userAnswer;
            cout << endl;

            int correctAnswer = qToDisplay.correctOption;
            
            if (isdigit(userAnswer[0]) && stoi(userAnswer) == correctAnswer)
            {
                cout << "Your answer is correct!" << endl;
                userScore++;
            }

            else
            {
                cout << "Your answer is incorrect..." << endl;
            }

           
            cout << "Press Enter to continue...";
            getchar();
            cin.ignore();
        }

        cout << "Your final score is: " << userScore << endl;
        cout << endl;

        highScores = appendScores(highScores, userName, userScore);
        displayScores(highScores);
        writeScoresToFile(highScores, "highscore.txt");

        cout << "Do you want to repeat the quiz? (y/n): ";
        cin >> repeatChoice;
        
        if (repeatChoice != 'y' && repeatChoice != 'Y')
        {
            break;
        }

        userScore = 0;
        askedQuestions.clear();

    } while (true);
}