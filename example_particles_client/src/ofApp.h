#pragma once

// This example is a port of the GPU particle example, but with a twist:
// The position texture is streamed via ofxLibwebsockets to clients!

#include "ofMain.h"
#include "ofxLibwebsockets.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

        ofxLibwebsockets::Client client;
    
        ofBuffer buff;
        ofMutex  mutex;
    
        // websocket methods
        void onConnect( ofxLibwebsockets::Event& args );
        void onOpen( ofxLibwebsockets::Event& args );
        void onClose( ofxLibwebsockets::Event& args );
        void onIdle( ofxLibwebsockets::Event& args );
        void onMessage( ofxLibwebsockets::Event& args );
        void onBroadcast( ofxLibwebsockets::Event& args );
    
        // begin GPU Particle vars
        // notice we're only using the rendering logic! :)
        void setupGPUParticles();
        void updateGPUParticles();
    
        ofShader    updateRender;
    
        ofFbo   posFBO, renderFBO;
        
        ofImage sparkImg;
        
        float   timeStep;
        float   particleSize;
        
        int     width, height;
        int     imgWidth, imgHeight;
        int     numParticles;
        int     textureRes;
    
        ofVboMesh mesh;
        // end GPU particle vars
};
