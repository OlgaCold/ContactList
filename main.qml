import QtQuick 2.9
import QtQuick.Controls 2.2
import QtGraphicalEffects 1.0
import QtQuick.Controls.Styles 1.4

import Backend 1.0


ApplicationWindow {
    id: root
    visible: true
    width: 180
    height: 200
    title: qsTr("My Contacts")


    ContactModel{
        id: contactModel
    }

        ListView{

            width: parent.width;
            height: parent.height;

            Component {
                id: contactDelegate

                Rectangle {
                    id: wrapper
                    width: parent.width
                    height: contactInfo.height
                    radius: 5
                    border.color: ListView.isCurrentItem ? "gainsboro" : "grey"
                    color: ListView.isCurrentItem ? "grey" : "gainsboro"

                    Rectangle{
                        id: imageWrapper
                        width: contactInfo.height*4/5
                        height: contactInfo.height*4/5
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: contactInfo.height*4/20
                        radius: 15
                        border.width: 10
                        border.color: ListView.isCurrentItem ? "gainsboro" : "grey"

                        Image{
                            id: contactImage
                            source: image
                            smooth: true
                            visible: false
                            anchors.fill: parent
                            fillMode: Image.Stretch
                            horizontalAlignment: Image.AlignLeft
                        }
                        Rectangle{

                            id: mask
                            width: parent.width
                            height: parent.height
                            radius: 15
                            smooth: false
                            visible: false//
                        }

                        OpacityMask {
                            anchors.fill: contactImage
                            source: contactImage
                            maskSource: mask
                        }
                    }

                    Text {
                        id: contactInfo
                        height: 26
                        font.pixelSize: 12
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                        text: name
                        color: wrapper.ListView.isCurrentItem ? "white" : "black"
                    }

                    RoundButton {
                        font.pixelSize: 5
                        text: qsTr("call")
                        height: contactInfo.height*4/5
                        width: contactInfo.height*4/5
                        highlighted: true
                        anchors.rightMargin: contactInfo.height*4/20
                        anchors.right: parent.right
                        anchors.verticalCenter: parent.verticalCenter
                        onClicked: {
                            contactModel.call(index)
                            var component = Qt.createComponent("call.qml")
                            var window    = component.createObject(root)
                            window.show()
                        }
                    }
                }
            }
            model: ContactModel {}
            delegate: contactDelegate

            focus: true
        }

}

