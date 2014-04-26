#include "testApp.h"
//#include <boost/lambda/lambda.hpp>
//--------------------------------------------------------------
//ofVec2f mouse = ofVec2f(ofGetMouseX(), ofGetMouseY());
typedef vector<vector<float> > vvf;
typedef vector<pair<float, float> > vp;
typedef vector<float> vf;
vf square;
vvf coords;

vp cloudcoords;
vp cloudmoves;
vp cloudpos;
float cloudmovex;
float cloudmovey;
int flipx, flipy;

int k;
vp undulate;

void testApp::setup(){
    k = 0;
    cloudmovex = 0;
    cloudmovey = 0;
    flipx = 1;
    flipy = 1;
	//random directions to simulate cloud movement
    
    
    ofSetWindowShape(1400,1000);
    
    
    heat.loadImage("images/scene4.png");
    /*unsigned char * pix = heat.getPixels();
     int brightness = 100;
     //for a 3 channel rgb image
     for(int i = 0; i < heat.width * heat.height * 3; i++){
     pix[i] += MIN(brightness, 255-pix[i]); //this makes sure it doesn't go over 255 as it will wrap to 0 otherwise.
     }
     heat.update();
     */
    
    //logo.loadFont("froufrou.ttf", 32);
    logo.loadFont("type/verdana.ttf", 25, true, false, true, 0.1, 102);
    //author.loadFont("froufrou.ttf", 15, true, false, true, 0.1, 102);
    author.loadFont("type/verdana.ttf", 15, true, false, true, 0.1, 102);
    //font.loadFont("sans-serif", 30);
    
    
    font6.loadFont("type/verdana.ttf", 8, true, false, true, 0.1, 102);
    font7.loadFont("type/verdana.ttf", 8, true, false, true, 0.1, 102);
    
    
    for(int i = 0; i<100; i++){
		float randomx = ofRandom(-100, 100);
        float randomy = ofRandom(-100, 100);
        cloudcoords.push_back(make_pair<float, float> ( randomx, randomy));
	}
    
    for(int i = 0; i<100; i++){
		float randomx = ofRandom(-.01,.01);
        float randomy = ofRandom(-.001,.001);
        cloudmoves.push_back(make_pair<float, float> ( randomx, randomy));
	}
    
    for(int i = 0; i<100; i++){
		float randomx = ofRandom(-.001,.001);
        float randomy = ofRandom(-.001,.001);
        undulate.push_back(make_pair<float, float> ( randomx, randomy));
	}
    
    
    
    mouse =false;
    
    enlarge = 100;
    nextpageleft = false;
    nextpageright = false;
    
    numberflipsleft = 0;
    numberflipsright = 0;
    
    totalflips = 0;
    page = 0;
    
    timeelapsed = 0;
    timeexit = 0;
    startpage = 0;
    stayonpage = false;
    
    resetrotate = false;
    for(int i = 0; i< 80; i++){
        rotateface = false;
        rotate.push_back(rotateface);
    }
    
    
    
    
    
    
    
    
    
    
    //without this we get a grey background
    /*
     ofSetVerticalSync(true);
     ofSetFrameRate(60);
     ofBackground(10, 10, 10);
     ofEnableDepthTest();
     
     // turn on smooth lighting //
     bSmoothLighting     = true;
     ofSetSmoothLighting(true);
     
     // lets make a high-res sphere //
     // default is 20 //
     ofSetSphereResolution(128);
     
     // radius of the sphere //
     radius		= 180.f;
     center.set(ofGetWidth()*.5, ofGetHeight()*.5, 0);
     
     
     
     // Point lights emit light in all directions //
     // set the diffuse color, color reflected from the light source //
     pointLight.setDiffuseColor( ofColor(0.f, 255.f, 255.0f));
     
     // specular color, the highlight/shininess color //
     pointLight.setSpecularColor( ofColor(255.f, 255.f, 0.f));
     pointLight.setPointLight();
     
     
     
     spotLight.setDiffuseColor( ofColor(255.f, 0.f, 0.f));
     spotLight.setSpecularColor( ofColor(255.f, 255.f, 255.f));
     
     // turn the light into spotLight, emit a cone of light //
     spotLight.setSpotlight();
     
     // size of the cone of emitted light, angle between light axis and side of cone //
     // angle range between 0 - 90 in degrees //
     spotLight.setSpotlightCutOff( 50 );
     
     // rate of falloff, illumitation decreases as the angle from the cone axis increases //
     // range 0 - 128, zero is even illumination, 128 is max falloff //
     spotLight.setSpotConcentration( 45 );
     
     
     // Directional Lights emit light based on their orientation, regardless of their position //
     directionalLight.setDiffuseColor(ofColor(0.f, 0.f, 255.f));
     directionalLight.setSpecularColor(ofColor(255.f, 255.f, 255.f));
     directionalLight.setDirectional();
     
     // set the direction of the light
     // set it pointing from left to right -> //
     directionalLight.setOrientation( ofVec3f(0, 90, 0) );
     
     
     bShiny = true;
     // shininess is a value between 0 - 128, 128 being the most shiny //
     material.setShininess( 128);
     // the light highlight of the material //
     material.setSpecularColor(ofColor(255, 255, 255, 255));
     
     bPointLight = bSpotLight = bDirLight = true;
     
     // tex coords for 3D objects in OF are from 0 -> 1, not 0 -> image.width
     // so we must disable the arb rectangle call to allow 0 -> 1
     ofDisableArbTex();
     // load album covers to use as the texture //
     */
    bUseTexture = true;
    
    
    
    
    
    
    
    
    
    
    float incx, incy, rotate;
    for(int i =0; i <600; i++){
        incx = ofRandom(-10, 10);
        incy = ofRandom(-10, 10);
        rotate = ofRandom(-15, 15);
        //cout<<"x is "<<incx<<" y is "<<incy<<" rotate is " <<rotate<<endl;
        square.push_back(incx);
        square.push_back(incy);
        square.push_back(rotate);
        coords.push_back(square);
        square.clear();
    }
}

//--------------------------------------------------------------
void testApp::update() {
    //ofBackground(185,184,174);            website color
    pointLight.setPosition(cos(ofGetElapsedTimef()*.6f) * radius * 2 + center.x,
						   sin(ofGetElapsedTimef()*.8f) * radius * 2 + center.y,
						   -cos(ofGetElapsedTimef()*.8f) * radius * 2 + center.z);
	
    spotLight.setOrientation( ofVec3f( 0, cos(ofGetElapsedTimef()) * RAD_TO_DEG, 0) );
	spotLight.setPosition( mouseX, mouseY, 200);
    
    float x, y;
    ofVec2f mouse = ofVec2f(ofGetMouseX(), ofGetMouseY());
    x = mouse.x;
    y = mouse.y;
    
    
    
}

//deperecated since "pushing forward" out of the screen is relative to orientation, not necessarily just changing the z component
void testApp::emerge(){
    ofTranslate(0,0,enlarge);
}
//--------------------------------------------------------------
void testApp::draw(){
    float x,y,z;
    
    
    string nabokov1 = "Phenomenal nature shadows him wherever he goes. Clouds in the staring sky transmit to each other, by means of slow signs, incredibly detailed information regarding him. ";
    vector<string>clouds;
	
	
	string nabokov2 = "His in-most thoughts are discussed at nightfall, in manual alphabet, by darkly gesticulating trees. Pebbles or stains or sun flecks form patterns representing, in some awful way, messages that he must intercept.";
    string nabokov3 = "Everything is a cipher and of everything he is the theme. All around him, there are spies.";
    string nabokov4 = "Some of them are detached observers, like glass surfaces and still pools; others, such as coats in store windows, are prejudiced witnesses, lynchers at heart; others, again (running water, storms), are hysterical to the point of insanity, have a distorted opinion of him, and grotesquely misinterpret his actions. ";
    string nabokov5 = "He must be always on his guard and devote every minute and module of life to the decoding of the undulation of things. ";
    string nabokov6 = "The very air he exhales is indexed and filed away.";
    string nabokov7 = "If only the interest he provokes were limited to his immediate surroundings, but, alas, it is not! ";
    string nabokov8 = "With distance, the torrents of wild scandal increase in volume and volubility. ";
    string nabokov9 = "The silhouettes of his blood corpuscles, magnified a million times, flit over vast plains; and still farther away, great mountains of unbearable solidity and height sum up, in terms of granite and groaning firs, the ultimate truth of his being.";
    
    
    ofSetColor(135,0,0);
    logo.drawStringAsShapes(" Signs and Symbols", 370,50);
    //author.drawStringAsShapes(" (by Tian Xu)", 500,68);
    
    ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 10, 15);
    
    
    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2, 0);
    ofRotateX(mouseY);
    ofRotateY(mouseX);
    
    
    
    
    float deg;
    int height;
    height = -60;
    ofPushMatrix();
    //ofTranslate(150, 480, 100);
    
    ofSetColor(135,0,0);
    
    
    
    
    
    x=0;
    vector<int> ycoords6;
    vector<int> zcoords6;
    for (int i = 0; i<52; i++){
        y = .1*(x+5*i);
        ycoords6.push_back(y);
    }
    
    //char[]c = naboko9.toCharArray();
    //divide into 3 rows
    ofPushMatrix();
    ofTranslate(-400,0,0);
    //ofPushMatrix();
    ofRotate(50,0,1,0);
    for(int i = 0; i<16; i++)
        font6.drawStringAsShapes(nabokov6.substr(i,1), x+i*5, ycoords6[i]);
    //ofPopMatrix();
    
    //ofTranslate(-400,0,0);
    ofTranslate(10,10,30);
    //ofPushMatrix();
    ofRotate(10,0,1,0);
    for(int i = 16; i<35; i++)
        font6.drawStringAsShapes(nabokov6.substr(i,1), x+(i-17)*5, ycoords6[i]);
    //ofPopMatrix();
    
    ofTranslate(10,10,20);
    //ofPushMatrix();
    ofRotate(10,0,1,0);
    for(int i = 35; i<51; i++)
        font6.drawStringAsShapes(nabokov6.substr(i,1), x+(i-36)*5, ycoords6[i]);
    //ofPopMatrix();
    ofPopMatrix();
    
    
    
    
    
    
    
    //cloud like movement
    vector<int> ycoords2;
    vector<int> zcoords2;
    ofPushMatrix();
    ofTranslate(-100,-50,0);
    //ofRotate(60,0,1,0);
    for(int i = 0; i<50; i++){
        pair<float, float> position = cloudcoords[i];
        float x = position.first;
        float z = position.second;
        
        pair<float, float> dir = cloudmoves[i];
        float xdir = dir.first;
        float ydir = dir.second;
        
        cloudmovex += flipx * xdir;
        cloudmovey += flipy * ydir;
        //cout<<"cloudmovex is"<<cloudmovex<<endl;
        //bounceoffwalls();
        if((cloudmovex <= -5) || (cloudmovex >= 5))
            flipx *= -1;
        if((cloudmovey <= -5) || (cloudmovey >= 5))
            flipy *= -1;
        ofTranslate(cloudmovex,0,cloudmovey);
        ofPushMatrix();
        ofTranslate(0,0,z);
        font6.drawStringAsShapes(nabokov1.substr(i,1), x,0);
        ofPopMatrix();
    }
    ofPopMatrix();
    
    
    
    
    
    ofPushMatrix();
	ofTranslate(100,0,0);
	for(int i = 0; i< 100; i++){
		pair<float, float> position = undulate[i];
        float x = position.first;
        float z = position.second;
		float oscillatex = ofRandom(-1,1);
		float oscillatey = ofRandom(-1,1);
        
		ofPushMatrix();
		font6.drawStringAsShapes(nabokov2.substr(i,1), x+10*i + oscillatex, y + oscillatey);
		ofPopMatrix();
	}
    ofPopMatrix();
    
    
    
    
    
    
    
    
    
    //so x^2/a^2 + y^2/b^2 + z^2/c^2 = 1; typical ellipsoid
    //x^2/a^2 + y^2/b^2    ; typical ellipse
    //lets take a random function, x^4/10 -8x+ y^2/10  = 1000, this looks like a slightly elongated ellipse
    
    //x^2 + y^2 = 10000
    
    
    vector<int> ycoords1;
    vector<int> zcoords1;
    
    vector<int> z2coords1;
    vector<int> z3coords1;
    vector<int> z4coords1;
    
    float z1, z2, z3;
    //we'll be using the xz plane considering OF's orientation
    //x^4/10 -8x+ y^2/10  = 1000
    x = 10; //to -10 14 steps total, let's do increments of .5 or 28 letters packed into 14 pixels..
    for (int i = 0; i < 165; i++){
        x = x+3;
        //z = sqrt(10*(10000 - (pow(x,2)/10) + 8*x));
        //z = sqrt(10000-pow(x,2));
        //z1 = pow(x/5,2)-2*x;
        //z1 = (x-10)*(x-15)*(x-22)*(x-35)*(x-50)*(x-63)*.000001;
        z1 = (x-30)*(x-60)*(x-90)*(x-140)*(x-200)*(x-250)*.000000001;
        zcoords1.push_back(z1);
        
        z2 = (x-30)*(x-60)*(x-90)*(x-140)*(x-200)*(x-250)*.000000001;
        z2coords1.push_back(z2);
        
		z3 = (x-30)*(x-60)*(x-90)*(x-140)*(x-200)*(x-250)*.000000001;
		z3coords1.push_back(z3);
        //cout<<"z2 coordinate is "<<z2<<endl;
		//z2 =
		//z2, z3, z4 respectively...
    }
    
    
    x=10;
    ofTranslate(0,100,0);
    
	ofPushMatrix();
    //ofRotate(60,0,1,0);
    for(int i=5; i<160; i++){
        //cout<<"the z coord is "<<zcoords1[i]<<endl;
        ofPushMatrix();
        //ofRotate(40,0,1,0);
        
		font7.drawStringAsShapes(nabokov9.substr(i,1), x+3*i, zcoords1[i]);
        ofPopMatrix();
	}
	ofPopMatrix();
    k++;
    
    ofRotate(40,0,1,0);
    ofPushMatrix();
    for(int i = 5; i<160; i++){
        ofPushMatrix();
        //ofRotate(100,0,1,0);
        font6.drawStringAsShapes(nabokov9.substr(i,1), x+2*i, z2coords1[i]);
        ofPopMatrix();
	}
    ofPopMatrix();
	
    
	ofRotate(50,0,1,0);
    ofPushMatrix();
	for(int i = 0; i< 160; i++){
		font6.drawStringAsShapes(nabokov9.substr(i,1), x+2*i, z3coords1[i]);
	}
	ofPopMatrix();
    
    
	
    ofPushMatrix();
    //ofSetLineWidth(3);
    //ofNoFill();
    ofBezier(10,10,55,15,15,210,100,200);
    ofPopMatrix();
    
    
    
    
    
    
    
    
    /*
     vector<float> zcoords8;
     vector<float> z2coords8;
     vector<float> z3coords8;
     vector<float> z4coords8;
     vector<float> z5coords8;
     for(int i = 0; i< 100; i++){
     x = x+2;
     z1 = (x-10)*(x-15)*(x-22)*(x-35)*(x-50)*(x-63)*.000001;
     zcoords8.push_back(z1);
     }
     */
    
    
	
	if (!bPointLight) pointLight.disable();
	if (!bSpotLight) spotLight.disable();
	if (!bDirLight) directionalLight.disable();
	
    material.end();
	// turn off lighting //
    ofDisableLighting();
    
	ofSetColor( pointLight.getDiffuseColor() );
	if(bPointLight) pointLight.draw();
    
    ofSetColor(255, 255, 255);
	ofSetColor( spotLight.getDiffuseColor() );
	if(bSpotLight) spotLight.draw();
	
    ofPopMatrix();
    
    
	/*ofDrawBitmapString("Point Light On (1) : "+ofToString(bPointLight) +"\n"+
     "Spot Light On (2) : "+ofToString(bSpotLight) +"\n"+
     "Directional Light On (3) : "+ofToString(bDirLight)+"\n"+
     "Shiny Objects On (s) : "+ofToString(bShiny)+"\n"+
     "Spot Light Cutoff (up/down) : "+ofToString(spotLight.getSpotlightCutOff(),0)+"\n"+
     "Spot Light Concentration (right/left) : " + ofToString(spotLight.getSpotConcentration(),0)+"\n"+
     "Smooth Lighting enabled (x) : "+ofToString(bSmoothLighting,0)+"\n"+
     "Textured (t) : "+ofToString(bUseTexture,0),
     20, 20);*/
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key) {
		case '1':
			bPointLight = !bPointLight;
			break;
		case '2':
			bSpotLight = !bSpotLight;
			break;
		case '3':
			bDirLight = !bDirLight;
			break;
		case 's':
			bShiny	= !bShiny;
			if (bShiny) material.setShininess( 120 );
			else material.setShininess( 30 );
			break;
        case 'o':
            axisrotate = true;
            break;
        case 'p':
            axisrotate = false;
            break;
        case 'n':
            nextpageleft = true;
            numberflipsleft++;
            resetrotate = true;
            break;
        case 'm':
            nextpageright = true;
            numberflipsright++;
            resetrotate = true;
            break;
        case 'x':
            bSmoothLighting = !bSmoothLighting;
            ofSetSmoothLighting(bSmoothLighting);
            break;
        case 't':
            bUseTexture = !bUseTexture;
            break;
        case OF_KEY_UP:
            // setSpotlightCutOff is clamped between 0 - 90 degrees //
            spotLight.setSpotlightCutOff(spotLight.getSpotlightCutOff()+1);
            break;
        case OF_KEY_DOWN:
            // setSpotlightCutOff is clamped between 0 - 90 degrees //
            spotLight.setSpotlightCutOff(spotLight.getSpotlightCutOff()-1);
            break;
        case OF_KEY_RIGHT:
            // setSpotConcentration is clamped between 0 - 128 //
            spotLight.setSpotConcentration(spotLight.getSpotConcentration()+1);
            break;
        case OF_KEY_LEFT:
            // setSpotConcentration is clamped between 0 - 128 //
            spotLight.setSpotConcentration(spotLight.getSpotConcentration()-1);
            break;
            
		default:
			break;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    /*cout<<"dragging at location x = "<<x<<" and y = "<<y<<endl;
     mousedrag.push_back(x);
     */
}
//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    /*cout<<"pressed at location x = "<<x<<" and y = "<<y<<endl;
     mouse = true;
     mousedrag.push_back(x);*/
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    /*cout<<"released at location x = "<<x<<" and y = "<<y<<endl;
     //mousedrag.clear();
     mouse = false;*/
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}