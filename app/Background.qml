import QtQuick 2.0

Canvas{
    anchors.fill: parent
    anchors.margins: 10
    property int w: width
    property int h: height

    function paintWinningCollumn(col){
        console.log("paint col", col)
        var ctx = getContext("2d")
        ctx.lineWidth = 5
        ctx.strokeStyle = "magenta"
        ctx.beginPath()
        ctx.moveTo(w/6 + (col * w/3), 0 )
        ctx.lineTo(w/6 + (col * w/3), h )
        ctx.stroke()
        ctx.closePath()
        requestPaint()
    }

    function paintWinningRow(col){
        var ctx = getContext("2d")
        ctx.lineWidth = 5
        ctx.strokeStyle = "magenta"
        ctx.beginPath()
        ctx.moveTo(0, h/6 + (col * h/3) )
        ctx.lineTo(w, h/6 + (col * h/3) )
        ctx.stroke()
        ctx.closePath()
        requestPaint()
    }

    function clear(){
        var ctx = getContext("2d")
        ctx.reset()
        ctx.clearRect(width, height);
        requestPaint()
    }

    function paintWinningSlash(slash){
        var begin = Qt.point(0,0)
        var end = Qt.point(w,h)

        if (slash > 0){
            begin = Qt.point(w,0)
            end = Qt.point(0,h)
        }

        var ctx = getContext("2d")
        ctx.lineWidth = 5
        ctx.strokeStyle = "magenta"
        ctx.beginPath()
        ctx.moveTo(begin.x, begin.y )
        ctx.lineTo(end.x, end.y )
        ctx.stroke()
        ctx.closePath()
        requestPaint()
    }

    onPaint: {
        var ctx = getContext("2d")
        ctx.lineWidth = 2
        ctx.strokeStyle = "blue"
        ctx.beginPath()
        ctx.moveTo(w/3, 0)
        ctx.lineTo(w/3 ,h);
        ctx.moveTo(w/3*2, 0)
        ctx.lineTo(w/3*2, h)
        ctx.moveTo(0, h/3)
        ctx.lineTo(w, h/3)
        ctx.moveTo(0, h/3*2)
        ctx.lineTo(w, h/3*2)
        ctx.closePath();
        ctx.stroke()
    }
}

