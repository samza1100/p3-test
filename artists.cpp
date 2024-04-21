#include <vector>
#include "artists.h"
using namespace std;


string Artist::getName(){
    //access Spotify API and retrieve artist name
    return name;
};
vector<string> Artist::getGenres(){
    //access Spotify API and retrieve genres associated with artist
    return genres;
};

vector<string> Artist::getTracks() {
    //access Spotify API and retrieve top tracks of artist
    return tracks;
}

int Artist::getPopularity(){
    //access API and retrieve popularity score associated with artist
    return popularity;
};

string Track::getTrackName() {
    return track_name;
}

Artist Track::getArtist() {
    return artist;
}

int Track::getTrackPopularity() {
    //access API and retrieve popularity score associated with track
    return trackPopularity;
}
