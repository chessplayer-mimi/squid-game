<!DOCTYPE html>
<html lang="zh">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>魷魚遊戲 - 數位版玻璃橋遊戲</title>
    <script>
        function startGame() {
            let level = 1;
            let lastAnswer = -1;
            let sameAnswerCount = 0;
            let winCount = 0;
            let maxLevel = 50;

            function playLevel() {
                if (level > maxLevel) {
                    alert("你已通過所有關卡！恭喜！");
                    return;
                }

                let answer = Math.floor(Math.random() * 2);
                let guess = prompt("第" + level + "關: 請輸入0或1");

                if (guess !== "0" && guess !== "1") {
                    alert("輸入錯誤，請輸入0或1。");
                    playLevel();
                    return;
                }

                if (parseInt(guess) === answer) {
                    alert("恭喜你通過第" + level + "關!");
                    sameAnswerCount = 0;
                    winCount++;

                    if (winCount % 5 === 0 && level < maxLevel) {
                        alert("恭喜你已經過了" + level + "關了。");
                    }

                    level++;
                    lastAnswer = answer;

                    if (level === 10) {
                        alert("雖然你還沒達到能達成的願望，但你已經獲得心態崩潰免疫了，此buff能祝福你接下來更容易通關。");
                    }

                    playLevel();
                } else {
                    if (parseInt(guess) === lastAnswer && sameAnswerCount === 2) {
                        alert("你以為答案都會是一樣的嗎");
                        sameAnswerCount = 0;
                    } else {
                        alert("你輸了");
                        sameAnswerCount++;
                    }

                    alert("你共通過了" + (level - 1) + "關。");
                    if (confirm("是否要再玩一次?")) {
                        level = 1;
                        lastAnswer = -1;
                        sameAnswerCount = 0;
                        winCount = 0;
                        playLevel();
                    }
                }
            }

            playLevel();
        }
    </script>
</head>
<body>
    <h1>歡迎參加魷魚遊戲!</h1>
    <p>這是數位版的玻璃橋遊戲。接下來將會沒有任何提示，你只能選0或1，你能夠活到第幾關呢?來挑戰看看吧!據說通過的能實現一個願望!</p>
    <button onclick="startGame()">開始遊戲</button>
</body>
</html>
