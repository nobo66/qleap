/* main.qml ---
;; 
;; Author: Julien Wintz
;; Created: Tue Mar 12 18:00:30 2013 (+0100)
;; Version: 
;; Last-Updated: Tue Mar 12 18:15:48 2013 (+0100)
;;           By: Julien Wintz
;;     Update #: 41
*/

/* Change Log:
;; 
*/

import QtQuick 2.0

Rectangle {

    width: 768;
    height: 1024;
    color: "#cccccc";
    
    Text {
      id: label_title;
      anchors.centerIn: parent;
      color: "#222222";
      text: "Move here!";
    }

    Text {
      id: label_coords;
      anchors.horizontalCenter: label_title.horizontalCenter;
      anchors.top: label_title.bottom;
      color: "#222222";
      text: "";
    }

    MouseArea {
      anchors.fill: parent;

              onPressed: label_coords.text =  "Pressed: " + "(" + mouse.x + ", " + mouse.y + ")";
             onReleased: label_coords.text = "Released: " + "(" + mouse.x + ", " + mouse.y + ")";
      onPositionChanged: label_coords.text =    "Moved: " + "(" + mouse.x + ", " + mouse.y + ")";
    }
}
