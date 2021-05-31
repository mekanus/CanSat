# CanSat Exp.
Conteúdo referente a experiência CanSat - criação dos circuitos de coleta de dados

**O conteúdo do repositório é sempre relacionado ao tema do mesmo, podendo entretanto, não estar limitado a somente ao tema.**

**O material aqui contido não possui finalidade comercial.**

## Preparação da IDE:

Instalar a biblioteca - https://github.com/mekanus/CanSat/blob/main/RF24-master.rar
Caso já tenha instalado outra biblioteca da IDE, remover a instalada primeiro.
Descompactar o conteúdo dentro de \Arduino\libraries (lembre-se de verificar onde está instalado o Arduino em seu computador).

## Sketchs e circutitos:

Existem 3 circuitos e seus respectivos Scketchs, sendo 2 referentes a versão de transmissão de dados sem fio.

O circuito é um coletor de dados, utilizando um Barômetro Bmp180 Gy-68 e um Acelerômetro Giroscópio 3 Eixos Mpu-6050. 

Na versão do circuito com Shield SD Card, os dados capturados são escritos em um arquivo .txt que fica gravado em um sd card.

Na versão de transmissão por RF, existem 2 circuitos: o circuito de captura dos dados e o circuito de recebimento e exibição que fica conectado a um computador com IDE Arduino e exibe os dados via monitor serial da IDE


## Links dos componentes na Mekanus Robótica Educacional

Acelerômetro Giroscópio 3 Eixos Mpu-6050 => https://www.lojamekanus.com.br/produto/408196/

Barômetro Bmp180 Gy-68 => https://www.lojamekanus.com.br/produto/408479/

Módulo Transceptor Nrf24l01 + Pa + Lna Rf Antena 2.4ghz => https://www.lojamekanus.com.br/produto/408507/

Módulo Leitor Gravador Micro Sd => https://www.lojamekanus.com.br/produto/408063/

## Montagem do circuito Cansat com Shield Sd Card 


Desenho do circuito: https://github.com/mekanus/CanSat/blob/main/CANSAT%20MICRO%20SD.JPG

Fonte: https://github.com/mekanus/CanSat/blob/main/CANSAT%20MicroSD.ino


## Montagem do circuito Cansat com os módulos NRF24l01


***Circuito emissor - Captura os dados e efetua o envio*** 

Desenho do circuito: https://github.com/mekanus/CanSat/blob/main/CANSAT%20NRF24L01_TX.JPG

Fonte: https://github.com/mekanus/CanSat/blob/main/CANSAT%20NRF24L01_TX.ino

***Circuito receptor - Recebe os dados para exibição via monitor serial da IDE*** 

Desenho do circuito: https://github.com/mekanus/CanSat/blob/main/CANSAT%20NRF24L01_RX.JPG

Fonte: https://github.com/mekanus/CanSat/blob/main/CANSAT%20NRF24L01_RX.ino


