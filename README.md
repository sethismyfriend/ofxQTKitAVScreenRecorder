ofxQTKitAVScreenRecorder
========================

Addon for OpenFrameworks that uses QTKit to save any pixel buffer (screengrab, or fbo) as well as audio to video file.

Works on Mac only, and includes and example that you can use to create an FBO with any draw functions, and write the out to a video. The example project includes modified versions of ofxQTKitRecorder, which someone posted in a forum, and gameovers ofxQTKitVideoGrabber, which I modified to have an audio only initialization in order to create the video files. The video files and audio files are created in the same time window, and then merged at the end into a single movie. This seems to work relatively well in our testing. 

The reason I'm posting this here is that we had a lot of trouble doing something which I thought was relatively strait forward. Most of the time in OF you are doing something that modifies the pixels - and thats what you want to save. The example file should be clear enough that you figure out how to add it to your project.