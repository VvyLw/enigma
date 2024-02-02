// random.js
"use strict";
let id;
let rand;
const generate = () => {
    const people = document.getElementById('num').value;
    if(isNaN(people)) {
        console.error("入力された値が数字ではありません。");
        return;
    }
    const num = [];
    const res = [];
    for(let i = 0; ++i <= 100;) {
        num.push(i);
    }
    for(let i = 0; i < parseInt(people); ++i) {
        const id = Math.floor(Math.random() * num.length);
        res.push(num[id]);
        num.splice(id, 1);
    }
    rand = [];
    for(let i = 0; i < parseInt(people); ++i) {
        const id = Math.floor(Math.random() * num.length);
        rand.push(num[id]);
        num.splice(id, 1);
    }
    id = 0;
    show();
};

const show = () => {
    const htmlRand = document.getElementById('result');
    htmlRand.innerHTML = `あなたの数字はこちら: ${rand[currentIndex]}<br>確認できたら「確認ボタン」を押し、次の人へ渡してください`;
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