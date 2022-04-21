<template>
    <div class="calculator">
        <div class="display">{{current||'0'}}</div>
        <div @click="clear" class="button">Clear</div>
        <div @click="sign" class="button">Plus/Minus</div>
        <div @click="percent" class="button">Percent</div>
        <div @click="divide" class="button operators">Divide</div>
        <div @click="append('7')" class="button">7</div>
        <div @click="append('8')" class="button">8</div>
        <div @click="append('9')" class="button">9</div>
        <div @click="multiply" class="button operators">Multiply</div>
        <div @click="append('4')" class="button">4</div>
        <div @click="append('5')" class="button">5</div>
        <div @click="append('6')" class="button">6</div>
        <div @click="sub" class="button operators">Subtract</div>
        <div @click="append('1')" class="button">1</div>
        <div @click="append('2')" class="button">2</div>
        <div @click="append('3')" class="button">3</div>
        <div @click="add" class="button operators">Add</div>
        <div class="button">''</div>
        <div @click="append('0')" class="button">0</div>
        <div @click="decimal" class="button">.</div>
        <div @click="equal" class="button operators">=</div>
    </div>
</template>

<script>
    export default {
        data() {
            return {
                previous: null,
                current: '',
                operator: null,
                operatorclicked: false,
            }
        },
        methods: {
            clear() {
                this.current = '';
            },
            sign() {
                this.current = this.current.charAt(0) === '-' ?
                    this.current.slice(1) : `-${this.current}`;
            },
            percent() {
                this.current = `${parseFloat(this.current) / 100}`;
            },
            append(number) {
                if (this.operatorclicked) {
                    this.current = '';
                    this.operatorclicked = false;
                }
                else if ((this.current == '') & (number=='0')) {
                    return
                }
                this.current = `${this.current}${number}`;
            },
            decimal() {
                if (this.current.indexof('.') === -1) {
                    this.append('.');
                }
            },
            setprevious() {
                this.previous = this.current;
                this.operatorclicked = true;
            },
            divide() {
                this.operator = (a, b) => a / b;
                this.setprevious();
            },
            multiply() {
                this.operator = (a, b) => a * b;
                this.setprevious();
            },
            sub() {
                this.operator = (a, b) => a - b;
                this.setprevious();
            },
            add() {
                this.operator = (a, b) => a + b;
                this.setprevious();
            },
            equal() {
                this.current = `${this.operator(
                    parseFloat(this.previous),
                    parseFloat(this.current)
                )}`;
                this.previous = null;
            }
        }
    };
</script>


<style scoped>
    .calculator{
        margin: 0 auto;
        width: 600px;
        font-size: 35px;
        display: grid;
        grid-template-columns: repeat(4, 1fr);
        grid-auto-rows: minmax(50px, auto);
    }
    .display{
        grid-column: 1/5;
        background-color: dimgray;
    }
    .button{
        background-color: darkorange;
        border: 2px solid #000000;
        color:white;
    }
    .operators{
    background-color:darkcyan;
    color:white;
    }
</style>

