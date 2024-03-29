// random.js
"use strict";
let id;
let rand;

const generate = () => {
    const people = document.getElementById('num').value;
    if (isNaN(people)) {
        console.error("入力された値が数字ではありません。");
        return;
    }
    const num = [];
    rand = [];
    for (let i = 0; ++i <= 100;) {
        num.push(i);
    }
    for (let i = 0; i < parseInt(people); ++i) {
        const j = Math.floor(Math.random() * num.length);
        rand.push(num[j]);
        num.splice(j, 1);
    }
    id = 0;
    show();
};

const show = () => {
    const htmlRand = document.getElementById('result');
    htmlRand.innerHTML = `あなたの数字はこちら: ${rand[id]}<br>確認できたら「確認」を押し、次の人へ渡してください`;
    if(id < rand.length - 1) {
        document.getElementById('confirm').style.display = 'block';
    } else {
        document.getElementById('confirm').style.display = 'none';
    }
};

document.getElementById('generate').addEventListener('click', generate);
document.getElementById('confirm').addEventListener('click', () => {
    id++;
    show();
});
