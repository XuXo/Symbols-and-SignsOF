#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void emerge();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofLight pointLight;
	ofLight spotLight;
	ofLight directionalLight;
	
	ofMaterial material;
    
    
    float enlarge;
    
    float timeelapsed;
    float timeexit;
    
    float startpage;
    bool nextpageleft;
    bool stayonpage;
    int numberflipsleft;
    
    
    bool nextpageright;
    int numberflipsright;
    
    int totalflips;
    int page;
    
    
    std::vector<float> mousedrag;
    bool mouse;
    bool mouseclick;
    
	float radius;
	ofVec3f center;
	bool bShiny;
    bool bSmoothLighting;
	bool bPointLight, bSpotLight, bDirLight;
    bool bUseTexture;
    
    int rownumber;
    
    vector<bool> loadmenu;
    vector<bool> rotate;
    vector<bool> freeze;
    bool scrollcubes;
    int cube;
    
    bool resetrotate;
    bool rotateface;
	bool axisrotate;
    
    int width = 6;
    
    float fontsize;
    ofTrueTypeFont  logo;
    ofTrueTypeFont  logo2;
    
    
    ofTrueTypeFont text6;
    
    ofTrueTypeFont	font1;
    ofTrueTypeFont  font2;
    ofTrueTypeFont	font3;
    ofTrueTypeFont	font4;
    ofTrueTypeFont	font5;
    ofTrueTypeFont	font6;
    ofTrueTypeFont	font7;
    ofTrueTypeFont	font8;
    ofTrueTypeFont	font9;
    ofTrueTypeFont	font10;
    ofTrueTypeFont  font11;
    ofTrueTypeFont  font12;
    ofTrueTypeFont	font13;
    ofTrueTypeFont  font14;
    ofTrueTypeFont  font15;
    
    
    int trans;
    
    ofTrueTypeFont  author;
    ofTrueTypeFont  date;
    ofTrueTypeFont  signature;
    vector<ofTrueTypeFont> songs;
    vector<string> tracks;
    
    vector<string> descriptions;
    ofTrueTypeFont caption;
    int captionindex;
    bool togglecaption;
    ofImage heat;
    
    ofColor songcolor;
    
    
    ofShader shader;
    bool doShader;
    
};
