#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <string>
#include <iostream>
using namespace std;
class PlaylistNode {
public:
    PlaylistNode();
    PlaylistNode(string initID, string userSong, string artist, int songLeng, PlaylistNode* nextLoc = 0);
    void InsertAfter(PlaylistNode* nodePtr);
    void SetNext(PlaylistNode* nodePtr);
    string GetSongName() const;
    string GetID() const;
    string GetArtistName() const;
    int GetSongLength() const;
    PlaylistNode* GetNext();
    void PrintPlaylistNode();

private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;
};
#endif