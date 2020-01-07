using namespace std;
using namespace sf;

class Score
{
private:
    string scoreString = "Score: ";
public:
    string getText(int point,int condition){
        stringstream ss;
        ss << point;
        string s;
        ss >> s;

        if (condition == 0){
            return scoreString+s;
        } else {
            return "Game Over: " + s + " points";
        }
    }

};
