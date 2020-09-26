#include <iostream>
#include <string.h>
using namespace std;

#define interface struct

interface Mp3
{
  virtual void playMp3(char * fileName) = 0;
};

interface Vlc 
{	
  virtual void playVlc(char * fileName) = 0;
};

interface Mp4 
{	
  virtual void playMp4(char * fileName) = 0;
};

class Mp3Player : public Mp3 
{
  public:
    void playMp3(char * fileName)
    {
      cout << "Playing mp3 file. Name: "  << fileName << endl;
    }
};

class VlcPlayer : public Vlc 
{
  public:
    void playVlc(char * fileName) 
    {
      cout << "Playing vlc file. Name: " << fileName << endl;
    }
};

class Mp4Player : public Mp4
{
   public:
    void playMp4(char * fileName) 
    {
      cout << "Playing mp4 file. Name: " << fileName << endl;	
    }
};

class MediaPlayer {
  private:
    Mp3 *mp3;
    Vlc *vlc;
    Mp4 *mp4;
  
  public:
    MediaPlayer() {
      mp3 = new Mp3Player();
      vlc = new VlcPlayer();
      mp4 = new Mp4Player();
    }

    void play(char * audioType, char * fileName)
    {
      if(stricmp(audioType, "mp3") == 0)
      {
        mp3->playMp3(fileName);	
      }  
      else if(stricmp(audioType, "vlc") == 0)
      {
        vlc->playVlc(fileName);
      }
      else if(stricmp(audioType, "mp4") == 0)
      {
        mp4->playMp4(fileName);
      }
    }
};

void main() {
  MediaPlayer *player = new MediaPlayer();

  player->play("mp3", "Homealone.mp3");
  player->play("mp4", "MissionImposible.mp4");
  player->play("vlc", "Fast&Furious.vlc");
}