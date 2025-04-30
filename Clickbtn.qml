import QtQuick
import QtQuick.Controls


Button{
    id: clickBtn
    height: 50
    width: 50

    Text {
        id: mainBtnText
        text: qsTr("Send command")
        font.pointSize: 6
        font.italic: true
        color: "black"
        wrapMode: Text.WordWrap
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        anchors.fill: parent
        anchors.margins: 4
    }
}

