import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import MessageList 1.0

Window {
    id: mainWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Rectangle{
        id: container
        width: mainWindow.width
        height: mainWindow.height
        color: "#282B2E"
            Rectangle{
                id:logo
                anchors.left: parent.left
                anchors.right: parent.right
                color: "red"
                height: 80
                Rectangle{
                    anchors.fill:parent
                    anchors.leftMargin: 15
                    anchors.rightMargin: 15
                    anchors.topMargin: 15
                    anchors.bottomMargin: 15
                    color: container.color
                    Text{
                        text: "iPassaHarte"
                        font.pointSize: 24
                        color: "white"
                        anchors.centerIn: parent
                    }
                }
            }


        Rectangle{
            anchors.top: logo.bottom
            anchors.left: container.left
            anchors.right: container.right
            anchors.bottom: container.bottom
            anchors.margins: 15
            color: "white"

            ScrollView {
                anchors.fill:parent
                ListView {
                    id: messageListView
                    model: messageList.model
                    anchors.fill: parent
                    delegate: Rectangle {
                             height: 25
                             width: parent.width
                             Text {
                                 text: modelData
                                 anchors.centerIn: parent
                             }
                         }
                }
            }
        }
    }
    MessageList{
        id: messageList
        onModelChanged: messageListView.model = messageList.model
    }

}
