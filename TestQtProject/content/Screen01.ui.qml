import QtQuick
import QtQuick.Controls
import TestQtProject

Rectangle {
    width: Constants.width
    height: Constants.height

    color: "#00ff0000"

    Text {
        text: qsTr("Γειά Σας")
        anchors.centerIn: parent
        font.family: Constants.font.family
        font.pixelSize: 24
    }
}
