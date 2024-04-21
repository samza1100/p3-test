#define ARTISTS_H

//#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Artist{
public:
    //should be private here, as the data for this class should be coming from the API, but since we weren't able to get the API integrated,
    //I have set it as public just for demonstration purposes. - Ahilan
    //These components of the class are basic components associated with the Artist Class in Spotify, just to mimic it
    //Ideally, we would be using different methodology
    string name;
    vector<string> genres;
    int popularity;
    vector<string> tracks; //This should be a vector<track>, but for the sake of simple demonstration-
    // -it will be set as a string vector


    //this would stay public
    string getName();
    vector<string> getGenres();
    vector<string> getTracks();
    int getPopularity();
};

struct Track{
    string track_name;
    Artist artist;
    int trackPopularity;

    string getTrackName();
    Artist getArtist();
    int getTrackPopularity();
};
