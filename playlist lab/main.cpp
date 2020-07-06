#include <iostream>
#include <iomanip>
using namespace std;
#include "Playlist.h"
using namespace std;
void PrintMenu(const string playlistTitle) {
    unsigned i = 0;
    char menuOp = ' ';
    string uniqueID;
    string songName;
    string artistName;
    int songLength = 0;
    int numNodes = 0;
    int songPosition = 0;
    int newPosition = 0;
    int totalTime;
    int count;
    PlaylistNode* newPrevNode = 0;
    PlaylistNode* newNode = 0;
    PlaylistNode* newSong = 0;
    PlaylistNode* currNode = 0;
    PlaylistNode* songNode = 0;
    PlaylistNode* prevNode = 0;
    PlaylistNode* insertPosNode = 0;
    PlaylistNode* headNode = 0;
    PlaylistNode* tailNode = 0;
    PlaylistNode* currPrintNode = 0;
    // Output menu option, prompt users for valid selection
    while (menuOp != 'q') {
        menuOp = ' ';
        cout << playlistTitle << " PLAYLIST MENU" << endl;
        cout << "a - Add song" << endl;
        cout << "d - Remove song" << endl;
        cout << "c - Change position of song" << endl;
        cout << "s - Output songs by specific artist" << endl;
        cout << "t - Output total time of playlist (in seconds)" << endl;
        cout << "o - Output full playlist" << endl;
        cout << "q - Quit" << endl << endl;
        while (menuOp != 'a' && menuOp != 'd' && menuOp != 'c' &&
            menuOp != 's' && menuOp != 't' && menuOp != 'o' && menuOp != 'q') {
            cout << "Choose an option:" << endl;
            cin >> menuOp;
        }
        // Call corresponding menu action
        switch (menuOp) {
        case 'a':
            // Prompt user for song information
            cout << "ADD SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            cin >> uniqueID;
            cout << "Enter song's name:" << endl;
            cin.ignore();
            getline(cin,songName);
            cout << "Enter artist's name:" << endl;
            getline(cin,artistName);
            cout << "Enter song's length (in seconds):" << endl;
            cin >> songLength;
                
            newSong = new PlaylistNode(uniqueID, songName, artistName, songLength);
            if (headNode == 0) {
               headNode = newSong;
               tailNode = newSong;
            }
            else {
               tailNode->InsertAfter(newSong);
               tailNode = tailNode->GetNext();
            }
            //cout << songName;
            numNodes++;
            cout << endl;
            break;

            // ... HIDDEN ... (you do the rest)
        case 'd':
            cout << "REMOVE SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            cin >> uniqueID;
            currNode = headNode->GetNext();
            prevNode = headNode;
            
            for(unsigned i = 0; i < numNodes; ++i) {
                if(currNode->GetID() != uniqueID) {
                    PlaylistNode* temp;
                    temp = currNode;
                    currNode = currNode->GetNext();
                    prevNode = temp;
                    delete temp;
                } // if statement
                else {
                    songName = currNode->GetSongName();
                    PlaylistNode* temp;
                    temp = currNode;
                    delete temp;
                    prevNode->SetNext(currNode->GetNext());
                    numNodes--;
                    break;
                }// else statement
            } // for loop
            cout << '"' << songName << '"' << " removed." << endl << endl; 
            break;
        
        case 'c':     
            cout << "CHANGE POSITION OF SONG" << endl;
            cout << "Enter song's current position:";
            cin >> songPosition;
            cout << endl;
            currNode = headNode;
            prevNode = headNode;
            count = 1;

            while (count < songPosition) {
                prevNode = currNode;
                currNode = currNode->GetNext();
                ++count;
            }
     
            if (headNode == currNode) {
                headNode = currNode->GetNext();
            } 
            else if (tailNode == currNode) {
                prevNode->SetNext(tailNode->GetNext());
                tailNode = prevNode;
            }
            else {
                prevNode->SetNext(currNode->GetNext());
            }       
            
            currNode->SetNext(nullptr);
            cout << "Enter new position for song:";
            cin >> songPosition;
            cout << endl;
            newPrevNode = headNode;
            count = 2;
        
            while (count < songPosition) {
                newPrevNode = newPrevNode->GetNext();
                ++count;
            }
    
            if (songPosition <= 1) {
                currNode->SetNext(headNode);
                headNode = currNode;
            }
      
            else if (songPosition > (numNodes - 1) ) {
                tailNode = currNode;
                newPrevNode->InsertAfter(currNode);
               
            }
            else {
               
                currNode->SetNext(newPrevNode->GetNext())    ;
                newPrevNode->SetNext(currNode);

            }
            cout << "\"" << currNode->GetSongName() << "\" moved to position " << songPosition << endl << endl;
            break; 
        
        case 's':
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            cout << "Enter artist's name:" << endl << endl;
            cin.ignore();
            getline (cin,artistName); 
            currNode = headNode;

            for(unsigned i = 1; i <= numNodes; ++i) {
                if(currNode->GetArtistName() == artistName) {
                    cout << i << '.' << endl;
                    currNode->PrintPlaylistNode();
                    cout << endl;
                }
                currNode = currNode->GetNext();
            }

            // while(currNode != nullptr) {
            //     if(i < numNodes) { 
            //         if(currNode->GetArtistName() == artistName) {
            //             cout << i+1 << '.' << endl;
            //             currNode->PrintPlaylistNode();
            //             cout << endl;
            //             currNode = currNode->GetNext();
            //             ++i;
            //         } // inside if statement
            //     }// if statement
            //     cout << "wow";
            // } // while loop
            break;
       
        case 't':
            for (currNode = headNode; currNode != nullptr; currNode = currNode->GetNext()) {
                totalTime = totalTime + currNode->GetSongLength();
             }
            cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
            cout << "Total time: " << totalTime << " seconds" << endl << endl;
            break;
          
        case 'o':
            cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
            currNode = headNode;
            if(currNode == nullptr) {
                cout << "Playlist is empty" << endl << endl;
            }

            for(unsigned i = 1; i <= numNodes; ++i) {
                cout << i << '.' << endl;
                currNode->PrintPlaylistNode();
                cout << endl;
                currNode = currNode->GetNext();
                }
        }
    }   
}

        int main() {
            string playlistTitle;
            // Prompt user for playlist title
            cout << "Enter playlist's title:" << endl;
            getline(cin, playlistTitle);
            cout << endl;
            // Output play list menu options
            PrintMenu(playlistTitle);
            return 0;
        }