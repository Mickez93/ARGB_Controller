import QtQuick
import QtQuick.Controls
import ConfHandler 1.0
import CmdHandler 1.0

Window {
    id: mainWindow
    objectName: "mainWindow"
    width: 640
    height: 480
    visible: true
    title: qsTr("ARGB Controller")
    color: "#2A3439"

    //Button to send commands
    Clickbtn
    {
        objectName: "clickBtn"
        height: myComboBox.height
        anchors
        {
            left: myComboBox.right
            verticalCenter: parent.verticalCenter
            leftMargin: 20
        }
        onClicked: {
            // Emit the signal when the button is clicked
            CommandHandler.btnSendCommand(myComboBox.currentText);
        }

    }

    ComboBox
    {
        id: myComboBox
        height: 30
        width: 200
        anchors.right: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        model: ConfigHandler.configFilesList
    }

    Column
    {
        spacing: 10
        anchors
        {
            left: parent.left
            right: parent.right
            verticalCenter: parent.verticalCenter
            leftMargin: 20
        }


        Slider
        {
            id: redSlider
            from: 0
            to: 255
            stepSize: 1

        }
        Slider
        {
            id: greenSlider
            from: 0
            to: 255
            stepSize: 1
        }
        Slider
        {
            id: blueSlider
            from: 0
            to: 255
            stepSize: 1
        }
    }
}
