import QtQuick
import QtQuick.Controls


Button{
    id: clickBtn
    height: 50
    width: 50
    signal sendCommandSig()

    Text {
        id: mainBtnText
        text: qsTr("Send command")
        font.pointSize: 8
        font.italic: true
        color: "black"
        wrapMode: Text.WordWrap
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        anchors.fill: parent
        anchors.margins: 4
        MouseArea
        {
            id: mainBtnMouseArea
            anchors.fill: parent
            onClicked: {
                // Emit the signal when the button is clicked
                console.log("Button clicked")
                clickBtn.sendCommandSig()
            }
        }
    }
}

