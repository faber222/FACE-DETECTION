#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	VideoCapture video(0); // coloque conforme for a sua webcam, se for linux, provavelmente seja a 0
	CascadeClassifier facedetect;
	Mat img;
	facedetect.load("haarcascade_frontalface_default.xml"); // xml contendo a rede neural de faces

	while (true) {
		video.read(img);

		vector<Rect> faces;

		facedetect.detectMultiScale(img, faces, 1.3, 5);

		cout << faces.size() << endl;

		for (int i = 0; i < faces.size(); i++) {
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(50, 50, 255), 3); // define a cor do retangulo e o preenchimento em volta da face
			rectangle(img, Point(0, 0), Point(250, 70), Scalar(0, 0, 255), FILLED); // define a cor e a posição do retangulo vermelho do contador
			if(faces.size() == 1){
				putText(img, to_string(faces.size()) + " Face Found", Point(10, 40), FONT_HERSHEY_DUPLEX, 1, Scalar(255, 255, 255), 1); // define o texto do contador
			} else{
				putText(img, to_string(faces.size()) + " Faces Found", Point(10, 40), FONT_HERSHEY_DUPLEX, 1, Scalar(255, 255, 255), 1);		
			}
		}
		imshow("Frame", img);
		waitKey(1);
	}
	return 0;
}
