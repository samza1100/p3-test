#include "mainwindow.h"
#include <QApplication>
#include <vector>
#include <set>
#include <algorithm>
#include "artists.h"
using namespace std;

//The two methods below me are just a basic algorithm for a quick sort, as the tracks will be sorted based on popularity
//In order for these to function to the fullest extent, we need the Spotify API to be integrated.
int partitionByPopularity(vector<Track> tracks, int start, int end){
    int pivot = tracks[end].getTrackPopularity();
    int index = start - 1;

    for(int i = start; i <= end; i++){
        if(tracks[i].getTrackPopularity() < pivot){
            index++;
            swap(tracks[index], tracks[i]);
        }
    }
    swap(tracks[index+1], tracks[end]);
    return index+1;
}

void quickSortByPopularity(vector<Track> tracks, int start, int end){
    if(start<end){
        int pivot = partitionByPopularity(tracks, start, end);
        quickSortByPopularity(tracks, start,pivot-1);
        quickSortByPopularity(tracks,pivot+1,end);
    }
}

//This is our key function to recommend songs based on the genre of the artists
vector<Track> recommendTopTracks(vector<Artist> artists){
    set<string> tracks; //This set will be where our recommended tracks will be inserted. It will get rid of duplicate tracks.
    set<Track> tracks2;
    //Normally, we should have a set<tracks> but for the sake of simple demonstration it will be a set<string>
    int popularityMean = 0; //this popularity mean will be used to determine the general popularity score of the artists the user has inputted
    int totalPopularity = 0;
    for(int i = 0; i < artists.size(); i++){
        totalPopularity += artists[i].getPopularity();
    }
    popularityMean = totalPopularity / artists.size();

    for(int i = 0; i < artists.size(); i++){
        vector<string> artistGenres = artists[i].getGenres();
        //From here, we're supposed to use Spotify API data, but we did not get it integrated...
        //Basically we are supposed to use the API to find other artists that have at least one of the same genres
        //We don't have the logic or the code for that here, since we didn't get the API integrated...

        vector<Track> tempTopTracks; //We retrieve the Top Songs of the artists and push them into the vector
        //This should be a vector of Tracks, but for sake of demonstration it is just a string vector

        //From there, we retrieve the popularity number from the tracks found and compare to the mean popularity score
        for(int i = 0; i < tempTopTracks.size(); i++) {
            int songPopularity = 0;
            //If they are within a range of +/- 10 of the popularity mean, we will insert it into our set.
            if ((songPopularity >= popularityMean && songPopularity <= popularityMean) ||
                (songPopularity <= popularityMean && songPopularity >= popularityMean - 10))
                tracks.insert(tempTopTracks[i].getTrackName());
        }
    }
    vector<Track> recommendedTracks;
    copy_n(tracks2.begin(), 10, std::back_inserter(recommendedTracks)); //set a limit to 10 so we only recommend 10 tracks
    quickSortByPopularity(recommendedTracks, 0, recommendedTracks.size()-1);

    return recommendedTracks;
};

//This is also our key function to recommend songs based on the genre of the artist, but this time will promote tracks
//considered underrated (popularity of 50 or lower)
vector<Track> recommendedUnderratedTracks(vector<Artist> artists){
    set<string> tracks; //This set will be where our recommended tracks will be inserted. It will get rid of duplicate tracks.
    set<Track> tracks2;
    //Normally, we should have a set<tracks> but for the sake of simple demonstration it will be a set<string>
    for(int i = 0; i < artists.size(); i++){
        vector<string> artistGenres = artists[i].getGenres();
        //From here, we're supposed to use Spotify API data, but we did not get it integrated...
        //Basically we are supposed to use the API to find other artists that have at least one of the same genres
        //We don't have the logic or the code for that here, since we didn't get the API integrated...

        vector<Track> tempTopTracks; //We retrieve the Top Songs of the artists and push them into the vector
        //This should be a vector of Tracks, but for sake of demonstration it is just a string vector

        //From there, we retrieve the popularity number from the tracks found and compare to the mean popularity score
        for(int i = 0; i < tempTopTracks.size(); i++) {
            int songPopularity = rand() % 100;
            //If they are less than or equal to 50 in popularity range
            if (songPopularity <= 50)
                tracks.insert(tempTopTracks[i].getTrackName());
        }
    }
    vector<Track> recommendedTracks;
    copy_n(tracks2.begin(), 5, std::back_inserter(recommendedTracks)); //set a limit to 5 so we only recommend 5 tracks
    //This one does not need to be sorted with a quick sort as it is not a top 10 list.
    return recommendedTracks;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    //test - Ahilan
}
