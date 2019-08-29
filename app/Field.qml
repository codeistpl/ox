import QtQuick 2.0

MouseArea{
    width: parent.width/3
    height: parent.height/3
    property int  row: 0
    property int col: 0
    property bool set : false
    function setX(){canvas.paintX()}
    function setO(){canvas.paintO()}
    function clear(){canvas.clear()}

    Canvas{
        id:canvas
        anchors.fill:parent
        anchors.margins: 10

        function clear(){
            var ctx = getContext("2d")
            ctx.reset()
            ctx.clearRect(0,0,width,height)
            requestPaint()
            set=false
        }

        function paintX(){

            var ctx = getContext("2d")
            ctx.reset()
            ctx.clearRect(0,0,width,height)
            ctx.lineWidth = 2
            ctx.strokeStyle = "red"
            ctx.moveTo(0,0)
            ctx.lineTo(width, height)
            ctx.moveTo(width,0)
            ctx.lineTo(0,height)
            ctx.stroke()
            requestPaint()
            set=true
        }

        function paintO(){
            var ctx = getContext("2d")
            ctx.reset()
            ctx.clearRect(0,0,width,height)
            ctx.lineWidth = 2
            ctx.strokeStyle = "green"
            ctx.arc(width/2, height/2, width/2-2, 0, 2*Math.PI)
            ctx.stroke()
            requestPaint()
            set=true
        }
    }
}
