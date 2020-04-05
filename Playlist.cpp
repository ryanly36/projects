#include "Playlist.h"

PlaylistNode::PlaylistNode() {
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    
}
PlaylistNode::PlaylistNode(string initID, string userSong, string artist, int songLeng, PlaylistNode* nextLoc) {
	uniqueID = initID;
    songName = userSong;
    artistName = artist;
    songLength = songLeng;
    nextNodePtr = nextLoc;
}

void PlaylistNode::InsertAfter(PlaylistNode* nodePtr) {
    PlaylistNode* temp = nullptr;

    temp = this->nextNodePtr;
    nextNodePtr = nodePtr;
    nodePtr = temp;
    delete temp;

}
void PlaylistNode::SetNext(PlaylistNode* nodePtr) {
    this->nextNodePtr = nodePtr;
}
string PlaylistNode::GetSongName() const {
    return songName;
}
string PlaylistNode::GetID() const {
    return uniqueID; 
}
string PlaylistNode::GetArtistName() const {
    return artistName; 
}
int PlaylistNode::GetSongLength() const {
    return songLength;
}

PlaylistNode* PlaylistNode::GetNext() {
    return this->nextNodePtr;
}
void PlaylistNode::PrintPlaylistNode() {
    cout << "Unique ID: " << uniqueID << endl;
    cout <<"Song Name: " << songName << endl;
    cout << "Artist Name: " << artistName << endl;
    cout << "Song Length (in seconds): " << songLength << endl; 
    }

