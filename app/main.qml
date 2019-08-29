import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import me.ox.gameadapter 1.0

Window {
    id:ox
    visible: true
    width: 640
    height: 480
    title: qsTr("OX")
    property var ids : [f00,f01,f02,f10,f11,f12,f20,f21,f22];
    property var player: 1
    property int scoreP1 : 0
    property int scoreP2: 0

    GameAdapter{
        id: backend
        onDataChanged: {
            for (var i=0; i<9; i++){
                if (data[i] === 1){
                    ids[i].setX();
                }else if(data[i] === 2){
                    ids[i].setO();
                }else{
                    ids[i].clear();
                }
            }
        }
        onPlayerChanged: {
            ox.player = player
        }

        onScoreChanged: {
            ox.scoreP1 = scoreP1;
            ox.scoreP2 = scoreP2;
        }
        onColumnWin:{
            background.paintWinningCollumn(idx);
        }
        onRowWin: {
            background.paintWinningRow(idx);
        }
        onDiagonalWin: {
            background.paintWinningSlash(0)
        }
        onRevDiagonalWin:
            background.paintWinningSlash(1);
    }



    Rectangle{
        id: panel
        border.color: "red"
        border.width: 1
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        implicitHeight: 50

        Grid{
            columns: 2
            rows: 2
            Text {
                id: p1Label
                text: qsTr("Player One:")
                color: ox.player === 1 ? "green" : "black"
            }
            Text {
                text: ox.scoreP1
                color: p1Label.color
            }
            Text{
                id:p2Label
                text: qsTr("Player Two:")
                color: ox.player === 2 ? "red" : "black"
            }
            Text {
                text: ox.scoreP2
                color: p2Label.color
            }
        }

        Button{
            anchors.centerIn: parent
            text: qsTr("Clear")
            onClicked: {backend.clear(); background.clear()}
        }

    }

    Rectangle{
        id:playground
        anchors.top: panel.bottom
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        height: parent.height
        width: height
        property int player : 0
        property  bool lockGame: false
        Background{
            id: background
        }

        function drawWin(){
            let col = game.getWinCollumnt();
            if (col > -1 ){
                background.paintWinningCollumn(col);
            }

            let row = game.getWinRow();
            if(row > -1){
                background.paintWinningRow(row)
            }

            let slash = game.getWinCross()
            if(slash > -1){
                background.paintWinningSlash(slash)
            }
            lockGame = true
        }

        Grid{
            anchors.fill: parent
            columns: 3
            rows:3

            Field{id:f00 ;onClicked:{backend.onFieldClick(0,0)}}
            Field{id:f01 ;onClicked:{backend.onFieldClick(0,1)}}
            Field{id:f02 ;onClicked:{backend.onFieldClick(0,2)}}
            Field{id:f10 ;onClicked:{backend.onFieldClick(1,0)}}
            Field{id:f11 ;onClicked:{backend.onFieldClick(1,1)}}
            Field{id:f12 ;onClicked:{backend.onFieldClick(1,2)}}
            Field{id:f20 ;onClicked:{backend.onFieldClick(2,0)}}
            Field{id:f21 ;onClicked:{backend.onFieldClick(2,1)}}
            Field{id:f22 ;onClicked:{backend.onFieldClick(2,2)}}
        }


    }
}
