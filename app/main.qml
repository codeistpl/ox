import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("OX")

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
                color: "red"
            }
            Text {
                text: "0"
                color: p1Label.color
            }
            Text{
                text: qsTr("Player Two:")
            }
            Text {
                text: "0"
            }
        }

        Button{
            anchors.centerIn: parent
            text: qsTr("Clear")
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
                console.log("have a winner!")
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

                Field{ no: 0
                    onClicked: {
                        if (!set && !playground.lockGame){
                            if(playground.player === 0){
                                setO();
                                playground.player = 1;
                                game.setO(0,0);
                            }else{
                                setX();
                                playground.player = 0;
                                game.setX(0,0);
                            }
                            if (game.haveWin()){
                                playground.drawWin()
                            }
                        }
                    }
                }
                Field{ no: 1
                    onClicked: {
                        if (!set && !playground.lockGame){
                            if(playground.player === 0){
                                setO();
                                playground.player = 1;
                                game.setO(0,1);
                            }else{
                                setX();
                                playground.player = 0;
                                game.setX(0,1);
                            }
                            if (game.haveWin()){
                                playground.drawWin()
                            }
                        }
                    }
                }
                Field{ no: 2
                    onClicked: {
                        if (!set && !playground.lockGame){
                            if(playground.player === 0){
                                setO();
                                playground.player = 1;
                                game.setO(0,2);
                            }else{
                                setX();
                                playground.player = 0;
                                game.setX(0,2);
                            }
                            if (game.haveWin()){
                                playground.drawWin()
                            }
                        }
                    }
                }
                Field{ no: 3
                    onClicked: {
                        if (!set && !playground.lockGame){
                            if(playground.player === 0){
                                setO();
                                playground.player = 1;
                                game.setO(1,0);
                            }else{
                                setX();
                                playground.player = 0;
                                game.setX(1,0);
                            }
                            if (game.haveWin()){
                                playground.drawWin()
                            }
                        }
                    }
                }
                Field{ no: 4
                    onClicked: {
                        if (!set && !playground.lockGame){
                            if(playground.player === 0){
                                setO();
                                playground.player = 1;
                                game.setO(1,1);
                            }else{
                                setX();
                                playground.player = 0;
                                game.setX(1,1);
                            }
                            if (game.haveWin()){
                                playground.drawWin()
                            }
                        }
                    }
                }
                Field{ no: 5
                    onClicked: {
                        if (!set && !playground.lockGame){
                            if(playground.player === 0){
                                setO();
                                playground.player = 1;
                                game.setO(1,2);
                            }else{
                                setX();
                                playground.player = 0;
                                game.setX(1,2);
                            }
                            if (game.haveWin()){
                                playground.drawWin()
                            }
                        }
                    }
                }
                Field{ no: 6
                    onClicked: {
                        if (!set && !playground.lockGame){
                            if(playground.player === 0){
                                setO();
                                playground.player = 1;
                                game.setO(2,0);
                            }else{
                                setX();
                                playground.player = 0;
                                game.setX(2,0);
                            }
                            if (game.haveWin()){
                                playground.drawWin()
                            }
                        }
                    }
                }
                Field{ no: 7
                    onClicked: {
                        if (!set && !playground.lockGame){
                            if(playground.player === 0){
                                setO();
                                playground.player = 1;
                                game.setO(2,1);
                            }else{
                                setX();
                                playground.player = 0;
                                game.setX(2,1);
                            }
                            if (game.haveWin()){
                                playground.drawWin()
                            }
                        }
                    }
                }
                Field{ no: 8
                    onClicked: {
                        if (!set && !playground.lockGame){
                            if(playground.player === 0){
                                setO();
                                playground.player = 1;
                                game.setO(2,2);
                            }else{
                                setX();
                                playground.player = 0;
                                game.setX(2,2);
                            }
                            if (game.haveWin()){
                                playground.drawWin()
                            }
                        }
                    }
                }
            }
        }
}
