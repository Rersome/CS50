function correct()
{
    let correct = document.querySelector('.correct');
    correct.style.backgroundColor = 'green';
    document.querySelector('#feedback1').innerHTML = 'Correct!';
}
function incorrect()
{
    let incorrects = document.querySelectorAll('.incorrect')
    for (let i = 0; i < incorrects.length; i++)
    {
        incorrects[i].addEventListener('click', function(){
            incorrects[i].style.backgroundColor = 'red';
            document.querySelector('#feedback1').innerHTML = 'Incorrect!';
        });
    }
}

function check()
{
    let input = document.querySelector('input');
    if (input.value == "Switzerland")
    {
        input.style.backgroundColor = 'green';
        document.querySelector('#feedback2').innerHTML = 'Correct!';
    }else
    {
        input.style.backgroundColor = 'red';
        document.querySelector('#feedback2').innerHTML = 'Incorrect!';
    }
}