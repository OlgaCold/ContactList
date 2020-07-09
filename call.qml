import QtQuick 2.9
import QtQuick.Controls 2.2

ApplicationWindow {
    id: root
    title: qsTr("Call")
    width: 100; height: 100

    Image{
        id: thisContactImage
        source: image
        smooth: true
        opacity: 0.5
        anchors.fill: parent
        fillMode: Image.Stretch
    }
    Text {
        anchors.centerIn: parent
        font.pixelSize: 12
        text: '<p><b> ' + name + '</p>' +
        qsTr("Call in progress...") +
              '<p><b> ' + number + '</p></b>'
    }
}
