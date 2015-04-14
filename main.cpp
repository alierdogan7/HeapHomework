#include <iostream>
using namespace std;

int main(int argCount, char *args[]) {
// args[0] is filename, args[1] is avgwaitingtime

    if(argCount != 2){
        cout << "Wrong arguments!" << endl;
        return 0;
    }

    string text("");
    string line;
    //ifstream myFile("sample.txt");
    ifstream myFile( args[0].c_str());

    if (myFile.is_open())
    {
      while ( getline(myFile, line) )
      {
        int pos = 0;
        int blankPos = line.find_first_of(" ");
        line.substr(pos, line.length() - blankPos);
        /*
        int counter = 0;
        while( !movieFile.eof() && counter < this->numMovies)
        {
            getline(movieFile, line);

            int pos = line.find_first_of(" ");
            //cout << pos << endl;

            int movieId, movieAmount;
            movieId = atoi( line.substr(0, pos).c_str() );
            movieAmount = atoi( line.substr(pos+1).c_str() );
            //cout << "/DEBUG/ movie " << movieId  << ", " << movieAmount <<  endl;

            movies[counter] = new Movie(movieId, movieAmount);
            counter++;
        }
        */
      }
      myFile.close();
    }
    else
    {
        cout << "Unable to open file" << endl;
        return;
    }

    for(int i = 0; i < text.length(); i++)
    {
        string tmp = "";
        for(int j = 0; j < n; j++)
        {
            if(i+j < text.length())  //if the string size is not exceeded
                tmp += text.at(i+j);

        }

        //cout << tmp << endl;
        std::size_t found;
        if( (tmp.length() != n) ||
            ( (found = tmp.find(' ') ) != string::npos) ||
            ( (found = tmp.find('\n') ) != string::npos) ) //npos is -1, if it contains empty space OR length is not equal to n, just ignore it
            continue;

        this->addNgram(tmp);
    }


    return 0;
}
