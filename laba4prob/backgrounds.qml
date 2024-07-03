import QtQuick 2.15

ApplicationWindow {
    id: window
    width: 800
    height: 600
    visible: true

    Image {
        id: backgroundImage
        anchors.fill: parent
        source: "background1.jpg"
        fillMode: Image.Stretch
    }

    Timer {
        id: backgroundTimer
        interval: 5000 // Время для смены фона в миллисекундах
        running: true
        repeat: true
        onTriggered: {
            changeBackground()
        }
    }
    function changeBackground() {
            var backgrounds = ["background1.jpg", "background2.jpg", "background3.jpg"]
            var randomIndex = Math.floor(Math.random() * backgrounds.length)
            backgroundImage.source = backgrounds[randomIndex]
        }
    }
