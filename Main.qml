import QtQuick
import QtQuick.Controls

Window {
    id: mainWindow
    objectName: "mainWindow"
    width: 640
    height: 480
    visible: true
    title: qsTr("ARGB Controller")
    color: "#2A3439"

    //Button to send commands
    Clickbtn {
        objectName: "clickBtn"
        anchors
        {
            verticalCenter: parent.verticalCenter
            horizontalCenter: parent.horizontalCenter
        }

    }
}
